#include "ray.h"

ray_t rays[NUM_RAYS];

bool isRayFacingDown(float angle) {
    return (angle > 0 && angle < PI);
}

bool isRayFacingUp(float angle) {
    return (!isRayFacingDown(angle));
}

bool isRayFacingRight(float angle) {
    return (angle < 0.5 * PI || angle > 1.5 * PI);
}

bool isRayFacingLeft(float angle) {
    return (!isRayFacingRight(angle));
}