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


bool isRayFacingUp(float angle);


bool isRayFacingDown(float angle);
bool isRayFacingLeft(float angle);
bool isRayFacingRight(float angle);
void castAllRays(void);
void castRay(float rayAngle, int stripId);
void renderMapRays(void);

#endif
