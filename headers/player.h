#ifndef PLAYER_H
#define PLAYER_H

#include "definitions.h"
#include "graphics.h"
#include "map.h"

/**
 * struct player_s - Structure to represent the player
 * @x: The x-coordinate of the player
 * @y: The y-coordinate of the player
 * @width: The width of the player
 * @height: The height of the player
 * @turnDirection: The direction in which the player is turning (-1 for left, +1 for right)
 * @walkDirection: The direction in which the player is walking (0 for no movement, +1 for forward, -1 for backward)
 * @rotationAngle: The angle at which the player is rotated
 * @walkSpeed: The speed at which the player can walk
 * @turnSpeed: The speed at which the player can turn
 */
typedef struct player_s
{
    float x;
    float y;
    float width;
    float height;
    int turnDirection;
    int walkDirection;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
} player_t;

extern player_t player; /* External declaration of the player variable */

void movePlayer(player_t *player, float deltaTime);
void renderMapPlayer(const player_t *player);
#endif /* PLAYER_H */