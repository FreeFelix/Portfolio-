#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

// Prototypes for ray-related functions
typedef struct {
    float distance;
    float wallHitX;
    float wallHitY;
    int texture;
    bool wasHitVertical;
    float rayAngle;
} ray_t;

extern ray_t rays[NUM_RAYS];

bool isRayFacingDown(float angle);
bool isRayFacingUp(float angle);
bool isRayFacingRight(float angle);
bool isRayFacingLeft(float angle);
void castRay(float rayAngle, int stripId);
void castAllRays(void);
void renderMapRays(void);

// Prototypes for utility functions
float distanceBetweenPoints(float x1, float y1, float x2, float y2);
bool isInsideMap(float x, float y);

#endif /* FUNCTIONS_H */