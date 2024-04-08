#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include "definition.h"
#include "draw.h"

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

/* Functions-variables-structs for map */
bool DetectCollision(float x, float y);
bool isInsideMap(float x, float y);
void renderMap(void);
int getMapValue(int row, int col);

#endif /* MAP_H */
