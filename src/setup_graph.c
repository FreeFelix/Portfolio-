#include "headers/inc_graphics.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static uint32_t *colorBuffer = NULL;
static SDL_Texture *colorBufferTexture;

/**
 * initializeWindow - Initialize the game window
 *
 * Return: true if window initialization is successful, otherwise false
 */
bool initializeWindow(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}
	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (!window)
	{
		fprintf(stderr, "Error creating SDL window.\n");
		return (false);
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		fprintf(stderr, "Error creating SDL renderer.\n");
		return (false);
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	colorBuffer = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)WINDOW_WIDTH *
									  (uint32_t)WINDOW_HEIGHT);
	colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
										   SDL_TEXTUREACCESS_STREAMING,
										   WINDOW_WIDTH, WINDOW_HEIGHT);
	return (true);
}

/**
 * destroyWindow - Destroy the game window and clean up resources
 */
void destroyWindow(void)
{
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/**
 * clearColorBuffer - Clear the color buffer with the specified color
 * @color: The color to clear the buffer with
 */
void clearColorBuffer(color_t color)
{
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
		colorBuffer[i] = color;
}

/**
 * renderColorBuffer - Render the color buffer to the screen
 */
void renderColorBuffer(void)
{
	SDL_UpdateTexture(colorBufferTexture, NULL, colorBuffer,
					  (int)((uint32_t)WINDOW_WIDTH * sizeof(color_t)));
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**
 * drawPixel - Draw a pixel at the specified coordinates with the specified color
 * @x: The x-coordinate of the pixel
 * @y: The y-coordinate of the pixel
 * @color: The color of the pixel
 */
void drawPixel(int x, int y, color_t color)
{
	colorBuffer[(WINDOW_WIDTH * y) + x] = color;
}

/**
 * drawRect - Draw a rectangle with the specified dimensions and color
 * @x: The x-coordinate of the top-left corner of the rectangle
 * @y: The y-coordinate of the top-left corner of the rectangle
 * @width: The width of the rectangle
 * @height: The height of the rectangle
 * @color: The color of the rectangle
 */
void drawRect(int x, int y, int width, int height, color_t color)
{
	for (int i = x; i <= (x + width); i++)
	{
		for (int j = y; j < (y + height); j++)
		{
			drawPixel(i, j, color);
		}
	}
}

/**
 * drawLine - Draw a line between two points with the specified color
 * @x0: The x-coordinate of the starting point of the line
 * @y0: The y-coordinate of the starting point of the line
 * @x1: The x-coordinate of the ending point of the line
 * @y1: The y-coordinate of the ending point of the line
 * @color: The color of the line
 */
void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	int deltaX;
	int deltaY;
	int longestSideLength;
	float xIncrement;
	float yIncrement;
	float currentX;
	float currentY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);
	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);
	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;
	currentX = x0;
	currentY = y0;

	for (int i = 0; i < longestSideLength; i++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}
