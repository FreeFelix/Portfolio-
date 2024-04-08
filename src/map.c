#include "../headers/definition.h"
#include "../headers/map.h"

static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 2, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 5},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 5}
};

/**
 * DetectCollision - Checks if there could be a collision with the wall
 * @x: Next x coordinate
 * @y: Next y coordinate
 * Description: This function checks if there could be a collision with the
 * wall in the next player advance, based on the given next coordinates.
 * Return: true if collision is detected, false otherwise.
 */

bool DetectCollision(float x, float y)
{
	int mapGridX, mapGridY;

	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE ||
			y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
		return (true);

	mapGridX = floor(x / TILE_SIZE);
	mapGridY = floor(y / TILE_SIZE);
	return (map[mapGridY][mapGridX] != 0);
}

/**
 * isInsideMap - Check if the coordinates are inside the map boundaries
 * @x: X coordinate
 * @y: Y coordinate
 * Description: This function checks if the given coordinates are inside
 * the boundaries of the map.
 * Return: true if coordinates are inside the map, false otherwise.
 */

bool isInsideMap(float x, float y)
{
	return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
				y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

/**
 * getMapValue - Get the value at a specific position in the map
 * @row: Row index in the map
 * @col: Column index in the map
 * Description: This function retrieves the value at the specified position
 * in the map.
 * Return: The value at the specified position in the map.
 */

int getMapValue(int row, int col)
{
	return (map[row][col]);
}

/**
 * renderMap - Render the map on the screen
 * Description: This function renders the map on the screen.
 * Return: No return value.
 */

void renderMap(void)
{
	int i, j, tileX, tileY;
	color_t tileColor;

	for (i = 0; i < MAP_NUM_ROWS; i++)
	{
		for (j = 0; j < MAP_NUM_COLS; j++)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tileColor = map[i][j] != 0 ? 0x00000000 : 0x03406F00;

			drawRect(
				tileX * MINIMAP_SCALE_FACTOR,
				tileY * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				tileColor
			);
		}
	}
}
