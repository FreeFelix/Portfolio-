#include <SDL2/SDL.h>
#include "../headers/definition.h"
#include "../headers/draw.h"

static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
static SDL_Window *window;

/**
 * initializeWindow - Initializes the window to display the maze.
 *
 * Description: This function initializes the SDL window
 * and renderer to display the maze. It also allocates memory
 * for the color buffer and creates an SDL texture to display
 * the color buffer.
 * Return: true if initialization is successful, otherwise false.
 */

bool initializeWindow(void)
{
	SDL_DisplayMode display_mode;
	int fullScreenWidth, fullScreenHeight;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}
	SDL_GetCurrentDisplayMode(0, &display_mode);
	fullScreenWidth = display_mode.w;
	fullScreenHeight = display_mode.h;
	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		fullScreenWidth,
		fullScreenHeight,
		SDL_WINDOW_BORDERLESS
	);
	if (!window)
	{
		fprintf(stderr, "Error creating SDL window.\n");
		return (false);
	}
	renderer = SDL_CreateRenderer(window, -1, 1);
	if (!renderer)
	{
		fprintf(stderr, "Error creating SDL renderer.\n");
		return (false);
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	/* allocate the total amount of bytes in memory to hold our colorbuffer */
	colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

	/* create an SDL_Texture to display the colorbuffer */
	colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	return (true);
}

/**
 * destroyWindow - Destroys the window and cleans up resources.
 *
 * Description: This function frees the memory allocated for the
 * color buffer, destroys the SDL texture and renderer, and quits SDL.
 * Return: None.
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
 * clearColorBuffer - Clears the color buffer for every frame.
 * @color: Color to clear the buffer with.
 *
 * Description: This function sets every pixel in the color
 * buffer to the specified color.
 * Return: None.
 */

void clearColorBuffer(color_t color)
{
	int i;

	for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		colorBuffer[i] = color;
}

/**
 * renderColorBuffer - Renders the color buffer for every frame.
 *
 * Description: This function updates the color buffer texture
 * with the contents of the color buffer and renders it to the screen.
 * Return: None.
 */

void renderColorBuffer(void)
{
	SDL_UpdateTexture(
		colorBufferTexture,
		NULL,
		colorBuffer,
		(int)(SCREEN_WIDTH * sizeof(color_t))
	);
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**
 * drawPixel - Draws a pixel with the specified color at the given
 * coordinates.
 * @x: X coordinate of the pixel.
 * @y: Y coordinate of the pixel.
 * @color: Color of the pixel.
 *
 * Description: This function sets the color of the pixel at the
 * specified coordinates in the color buffer.
 *
 * Return: None.
 */

void drawPixel(int x, int y, color_t color)
{
	colorBuffer[(SCREEN_WIDTH * y) + x] = color;
}

