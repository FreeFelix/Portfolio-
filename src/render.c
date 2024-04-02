#include "../headers/definition.h"
#include "../headers/input.h"

/**
 * SDL_KEYDOWN_FUNC - Process input when a key is down.
 *
 * @event: Union that contains structures for the different event types.
 *
 * Description:
 *     This function processes input events when a key is pressed down. It
 *     updates the game state based on the keys pressed.
 *
 * Return:
 *     No return value.
 */

void SDL_KEYDOWN_FUNC(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		GameRunning = false;
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = +1;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = +1;
	if (event.key.keysym.sym == SDLK_s)
		player.walkDirection = -1;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = -1;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = +1;
}

/**
 * SDL_KEYUP_FUNC - Process input when a key is up.
 *
 * @event: Union that contains structures for the different event types.
 *
 * Description:
 *     This function processes input events when a key is released. It updates
 *     the game state based on the keys released.
 *
 * Return:
 *     No return value.
 */

void SDL_KEYUP_FUNC(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_DOWN)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_RIGHT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_LEFT)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_w)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_s)
		player.walkDirection = 0;
	if (event.key.keysym.sym == SDLK_a)
		player.turnDirection = 0;
	if (event.key.keysym.sym == SDLK_d)
		player.turnDirection = 0;
}

/**
 * handleInput - Process input from the keyboard.
 *
 * Description:
 *     This function polls events from the keyboard and handles them
 *     accordingly by calling SDL_KEYDOWN_FUNC or SDL_KEYUP_FUNC based on the
 *     event type.
 *
 * Return:
 *     No return value.
 */
 
void handleInput(void)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
		GameRunning = false;
	else if (event.type == SDL_KEYDOWN)
		SDL_KEYDOWN_FUNC(event);
	else if (event.type == SDL_KEYUP)
		SDL_KEYUP_FUNC(event);
}
