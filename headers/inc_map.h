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

/**
 * mapHasWallAt - Check if there is a wall at the specified coordinates
 * @x: The x-coordinate to check
 * @y: The y-coordinate to check
 *
 * Returns:
 *   true if there is a wall at the specified coordinates, otherwise false
 */
bool mapHasWallAt(float x, float y);

/**
 * isInsideMap - Check if the specified coordinates are inside the map boundaries
 * @x: The x-coordinate to check
 * @y: The y-coordinate to check
 *
 * Returns:
 *   true if the coordinates are inside the map boundaries, otherwise false
 */
bool isInsideMap(float x, float y);

/**
 * renderMapGrid - Render the map grid to the screen
 */
void renderMapGrid(void);

/**
 * getMapAt - Get the value at the specified position in the map grid
 * @i: The row index
 * @j: The column index
 *
 * Returns:
 *   The value at the specified position in the map grid
 */
int getMapAt(int i, int j);

#endif
