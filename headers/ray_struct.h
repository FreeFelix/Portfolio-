#ifndef RAY_H
#define RAY_H

#include <stdbool.h>
#include <limits.h>
#include "inc_def.h"
#include "inc_player.h"

/**
 * ray_t - Structure representing a ray in the raycasting process
 * @rayAngle: The angle of the ray
 * @wallHitX: The x-coordinate where the ray hits a wall
 * @wallHitY: The y-coordinate where the ray hits a wall
 * @distance: The distance from the player to the wall hit by the ray
 * @wasHitVertical: Indicates if the wall hit by the ray is vertical
 * @texture: The texture index associated with the wall hit by the ray
 */
typedef struct {
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    bool wasHitVertical;
    int texture;
} ray_t;

extern ray_t rays[NUM_RAYS];

/**
 * isRayFacingUp - Check if the ray is facing upward
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing upward, otherwise false
 */
bool isRayFacingUp(float angle);

/**
 * isRayFacingDown - Check if the ray is facing downward
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing downward, otherwise false
 */
bool isRayFacingDown(float angle);

/**
 * isRayFacingLeft - Check if the ray is facing left
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing left, otherwise false
 */
bool isRayFacingLeft(float angle);

/**
 * isRayFacingRight - Check if the ray is facing right
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing right, otherwise false
 */
bool isRayFacingRight(float angle);

/**
 * castAllRays - Cast rays to determine the distance to walls and textures
 */
void castAllRays(void);

/**
 * castRay - Cast a single ray from the player's perspective
 * @rayAngle: The angle of the ray
 * @stripId: The identifier of the ray strip
 */
void castRay(float rayAngle, int stripId);

/**
 * renderMapRays - Render the rays on the map
 */
void renderMapRays(void);

#endif
