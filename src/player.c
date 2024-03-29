#include "../headers/player.h"
#include "../headers/utilse.h"

player_t	player =
{
	.x = WINDOW_WIDTH / 2,
	.y = WINDOW_HEIGHT / 2,
	.width = 1,
	.height = 1,
	.turnDirection = 0,
	.walkDirection = 0,
	.rotationAngle = PI / 2,
	.walkSpeed = 100,
	.turnSpeed = 45 * (PI / 180)
};

/**
 * movePlayer - Move the player based on the given delta time
 * @deltaTime: The time elapsed since the last frame
 */

void	movePlayer(float deltaTime)
{
	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;

	player.rotationAngle += player.turnDirection * player.turnSpeed * deltaTime;
	normalizeAngle(&player.rotationAngle);

	moveStep = player.walkDirection * player.walkSpeed * deltaTime;

	newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
	newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

	if (!mapHasWallAt(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
	}
}

/**
 * renderMapPlayer - Render the player on the map
 */

void	renderMapPlayer(void)
{
	drawRect
	(
		player.x * MINIMAP_SCALE_FACTOR,
		player.y * MINIMAP_SCALE_FACTOR,
		player.width * MINIMAP_SCALE_FACTOR,
		player.height * MINIMAP_SCALE_FACTOR,
		0xFFFFFFFF
	);
}