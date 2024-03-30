#include "../headers/graphics.h"

static SDL_Window		*window = NULL;
static SDL_Renderer		*renderer = NULL;
static uint32_t			*colorBuffer = NULL;
static SDL_Texture		*colorBufferTexture;

/**
 * initializeWindow - Initializes the SDL window and renderer
 *
 * Return: true upon successful initialization, false otherwise
 */
bool	initializeWindow(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}
	window = SDL_CreateWindow
	(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE
	);
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

	/**
	 * Allocate the total amount of bytes in memory to hold our colorbuffer.
	 */

	colorBuffer = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)WINDOW_WIDTH * (uint32_t)WINDOW_HEIGHT);

	/**
	 * Create an SDL_texture to display the colorbuffer.
	 */

	colorBufferTexture = SDL_CreateTexture
	(
		renderer,
		SDL_PIXELFORMAT_RGBA32,
		SDL_TEXTUREACCESS_STREAMING,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	);

	return (true);
}

/**
 * destroyWindow - Destroys the SDL window and associated resources
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
 * clearColorBuffer - Clears the color buffer with the specified color
 * @color: The color to clear the buffer with
 */
void clearColorBuffer(color_t color)
{
	int i;
	for (i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
		colorBuffer[i] = color;
}

/**
 * renderColorBuffer - Renders the color buffer onto the screen
 */
void renderColorBuffer(void)
{
	SDL_UpdateTexture
	(
		colorBufferTexture,
		NULL,
		colorBuffer,
		(int)((uint32_t)WINDOW_WIDTH * sizeof(color_t))
	);
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**
 * drawPixel - Draws a single pixel at the specified position with the specified color
 * @x: The x-coordinate of the pixel
 * @y: The y-coordinate of the pixel
 * @color: The color of the pixel
 */
void drawPixel(int x, int y, color_t color)
{
	colorBuffer[(WINDOW_WIDTH * y) + x] = color;
}

/**
 * drawRect - Draws a filled rectangle at the specified position with the specified dimensions and color
 * @x: The x-coordinate of the top-left corner of the rectangle
 * @y: The y-coordinate of the top-left corner of the rectangle
 * @width: The width of the rectangle
 * @height: The height of the rectangle
 * @color: The color of the rectangle
 */
void drawRect(int x, int y, int width, int height, color_t color)
{
	int i, j;
	for (i = x; i <= (x + width); i++)
	{
		for (j = y; j < (y + height); j++)
		{
			drawPixel(i, j, color);
		}
	}
}

/**
 * drawLine - Draws a line between two points with the specified color
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
	int i;

	/*  Differences between start and end of the line */
	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	/* Longest side of the line */
	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	/* Calculate the increment in each axis */
	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	/* Start at the first point */
	currentX = x0;
	currentY = y0;

	/* Loop all the longest side until the end */
	for (i = 0; i < longestSideLength; i++)
	{
		/* Draw pixel, rounding the values to integer to get nearest pixel */
		drawPixel(round(currentX), round(currentY), color);

		/* Increment the slope to get the next pixel */
		currentX += xIncrement;
		currentY += yIncrement;
	}
}
