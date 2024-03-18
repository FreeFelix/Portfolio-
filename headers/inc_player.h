#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h> // Add this line to include the "stdint.h" header
#include "inc_graphics.h"
#include "inc_map.h"

/**
 * player_t - Structure representing the player
 * @x: The x-coordinate of the player's position
 * @y: The y-coordinate of the player's position
 * @width: The width of the player's bounding box
 * @height: The height of the player's bounding box
 * @turnDirection: The direction in which the player is turning (-1 for left, +1 for right)
 * @walkDirection: The direction in which the player is walking (-1 for back, +1 for front)
 * @rotationAngle: The current rotation angle of the player
 * @walkSpeed: The speed at which the player walks
 * @turnSpeed: The speed at which the player turns
 */
typedef struct {
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

extern player_t player;

/**
 * movePlayer - Move the player based on the given delta time
 * @deltaTime: The time elapsed since the last frame
 */
void movePlayer(float deltaTime);

/**
 * renderMapPlayer - Render the player on the map
 */
void renderMapPlayer(void);

#endif
