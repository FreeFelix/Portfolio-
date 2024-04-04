#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../headers/draw.h"
#include "../headers/definition.h"
#include "../headers/input.h"
#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/ray.h"
#include "../headers/textures.h"
#include "../headers/wall.h"

/**
 * setup_game - Initializes player variables and loads wall textures.
 * Return: No return value.
 */
player_t player;
int TicksLastFrame = 0;
bool GameRunning = false;

void setup_game(void)
{
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 1;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
	player.turnDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
	WallTexturesready();
}


/**
 * update_game - Updates the game with delta time, ticks last frame,
 * player movement, and ray casting.
 * Return: No return value.
 */
void update_game(void)
{
	float DeltaTime;
	int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeToWait);
	}
	DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;

	TicksLastFrame = SDL_GetTicks();

	movePlayer(DeltaTime);
	castAllRays();
}

/**
 * render_game - Calls all functions needed for on-screen rendering.
 *  Return: No return value.
 */

void render_game(void)
{
	clearColorBuffer(0xFF000000);

	renderWall();

	renderMap();
	renderRays();
	renderPlayer();

	renderColorBuffer();
}
/**
 * destroy_game - Frees wall textures and destroys window.
 * Return: No return value.
 */
void destroy_game(void)
{
	freeWallTextures();
	destroyWindow();
}

/**
 * main - Main function.
 * Return: 0.
 */

int main(void)
{

	GameRunning = initializeWindow();

	setup_game();

	while (GameRunning)
	{
		handleInput();
		update_game();
		render_game();
	}
	destroy_game();
	return (0);
}
