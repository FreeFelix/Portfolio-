#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include "inc_def.h"
#include "inc_graphics.h"

/**
 * MAP_NUM_ROWS - Number of rows in the map grid
 */
#define MAP_NUM_ROWS 13

/**
 * MAP_NUM_COLS - Number of columns in the map grid
 */
#define MAP_NUM_COLS 20

bool mapHasWallAt(float x, float y);
bool isInsideMap(float x, float y);
void renderMapGrid(void);
int getMapAt(int i, int j);

#endif
