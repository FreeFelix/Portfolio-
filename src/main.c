#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../headers/definitions.h"
#include "../headers/graphics.h"
#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/raycast.h"
#include "../headers/wall.h"
#include "../headers/render.h"
#include "../headers/textures.h"

/**
 * bool isGameRunning - Indicates whether the game loop is running.
 */
bool isGameRunning = false;

/**
 * int ticksLastFrame - Stores the timestamp of the last frame.
 */
int ticksLastFrame;

/**
 * void setup(void) - Initializes the game environment.
 * This function loads textures using the uPNG library.
 */
void setup(void)
{
    /* Asks uPNG library to decode all PNG files and loads the wallTextures array */
    loadTextures();
}

/**
 * void processInput(void) - Handles user input events.
 * This function polls for SDL events and updates game state accordingly.
 */
void processInput(void)
{
    SDL_Event event;

    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
        {
            isGameRunning = false;
            break;
        }
        case SDL_KEYDOWN:
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isGameRunning = false;
            if (event.key.keysym.sym == SDLK_UP)
                player.walkDirection = +1;
            if (event.key.keysym.sym == SDLK_DOWN)
                player.walkDirection = -1;
            if (event.key.keysym.sym == SDLK_RIGHT)
                player.turnDirection = +1;
            if (event.key.keysym.sym == SDLK_LEFT)
                player.turnDirection = -1;
            break;
        }
        case SDL_KEYUP:
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isGameRunning = false;
            if (event.key.keysym.sym == SDLK_UP)
                player.walkDirection = 0;
            if (event.key.keysym.sym == SDLK_DOWN)
                player.walkDirection = 0;
            if (event.key.keysym.sym == SDLK_RIGHT)
                player.turnDirection = 0;
            if (event.key.keysym.sym == SDLK_LEFT)
                player.turnDirection = 0;
            break;
        }
    }
}

/**
 * void update(void) - Updates game state.
 * This function calculates delta time and moves game objects accordingly.
 */
void update(void)
{
    int timeToWait;
    float deltaTime;

    /* Compute how long we have until the reach the target frame time in milliseconds */
    timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticksLastFrame);

    /*  Only delay execution if we are running too fast */
    if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
    {
        SDL_Delay(timeToWait);
    }

    /* Compute the delta time to be used as an update factor when changing game objects */
    deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    /* Store the milliseconds of the current frame to be used in the future */
    ticksLastFrame = SDL_GetTicks();

    movePlayer(&player, deltaTime);
    castAllRays();
}

void	render(void)
{
	/* clear the color buffer */
	clearColorBuffer(0xFF000000);

	/* Render the wall and sprites */
	renderWallProjection();
	renderSpriteProjection();

	/* 
	 * Render the minimap objects
	 * display the minimap
	 */
	
	renderMapGrid();
	renderMapRays();
	renderMapSprites();
	renderMapPlayer(&player);

	renderColorBuffer();
}

/**
 * void releaseResources(void) - Releases allocated resources.
 * This function frees textures and destroys the game window.
 */
void releaseResources(void)
{
    freeTextures();
    destroyWindow();
}

/**
 * int main(void) - Entry point of the program.
 * Initializes the game window and runs the game loop until termination.
 * Returns EXIT_SUCCESS upon successful completion.
 */
int main(void)
{
    isGameRunning = initializeWindow();

    setup();

    while (isGameRunning) {
        processInput();
        update();
        render();
    }

    releaseResources();

    return (EXIT_SUCCESS);
}