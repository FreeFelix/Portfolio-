#include "../headers/player.h"
#include "../headers/utilse.h"

/**
 * player_t player - Structure to represent the player.
 * @x: The x-coordinate of the player.
 * @y: The y-coordinate of the player.
 * @width: The width of the player.
 * @height: The height of the player.
 * @turnDirection: The direction in which the player is turning (-1 for left, +1 for right).
 * @walkDirection: The direction in which the player is walking (0 for no movement, +1 for forward, -1 for backward).
 * @rotationAngle: The angle at which the player is rotated.
 * @walkSpeed: The speed at which the player can walk.
 * @turnSpeed: The speed at which the player can turn.
 */
player_t player = {
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
 * initializePlayer - Initializes a new player with default values.
 *
 * Returns:
 *   A player_t struct with default values.
 */
player_t initializePlayer(void) {
    player_t newPlayer;

    newPlayer.x = WINDOW_WIDTH / 2;
    newPlayer.y = WINDOW_HEIGHT / 2;
    newPlayer.width = 1;
    newPlayer.height = 1;
    newPlayer.turnDirection = 0;
    newPlayer.walkDirection = 0;
    newPlayer.rotationAngle = PI / 2;
    newPlayer.walkSpeed = 100;
    newPlayer.turnSpeed = 45 * (PI / 180);

    return newPlayer;
}

/**
 * movePlayer - Move the player based on the given delta time.
 * @player: Pointer to the player to be moved.
 * @deltaTime: The time elapsed since the last frame.
 */
void movePlayer(player_t *player, float deltaTime) {
    float moveStep;
    float newPlayerX;
    float newPlayerY;

    player->rotationAngle += player->turnDirection * player->turnSpeed * deltaTime;
    normalizeAngle(&player->rotationAngle);

    moveStep = player->walkDirection * player->walkSpeed * deltaTime;

    newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
    newPlayerY = player->y + sin(player->rotationAngle) * moveStep;

    if (!mapHasWallAt(newPlayerX, newPlayerY)) {
        player->x = newPlayerX;
        player->y = newPlayerY;
    }
}

/**
 * renderMapPlayer - Render the player on the map.
 * @player: Pointer to the player to be rendered.
 */
void renderMapPlayer(const player_t *player) {
    drawRect(
        player->x * MINIMAP_SCALE_FACTOR,
        player->y * MINIMAP_SCALE_FACTOR,
        player->width * MINIMAP_SCALE_FACTOR,
        player->height * MINIMAP_SCALE_FACTOR,
        0xFFFFFFFF
    );
}