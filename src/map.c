#include "../headers/map.h"

static const int	map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
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
 * mapHasWallAt - Check if there is a wall at the specified coordinates
 * @x: The x-coordinate to check
 * @y: The y-coordinate to check
 *
 * Returns:
 *   true if there is a wall at the specified coordinates, otherwise false
 */

bool	mapHasWallAt(float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;

	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE || y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
		return (true);

	mapGridIndexX = (floor)(x / TILE_SIZE);
	mapGridIndexY = (floor)(y / TILE_SIZE);
	return (map[mapGridIndexY][mapGridIndexX] != 0);
}

/**
 * isInsideMap - Check if the specified coordinates are inside the map boundaries
 * @x: The x-coordinate to check
 * @y: The y-coordinate to check
 *
 * Returns:
 *   true if the coordinates are inside the map boundaries, otherwise false
 */

bool	isInsideMap(float x, float y)
{
	return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE
		&& y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

/**
 * getMapAt - Get the value at the specified position in the map grid
 * @i: The row index
 * @j: The column index
 *
 * Returns:
 *   The value at the specified position in the map grid
 */

int		getMapAt(int i, int j)
{
	return (map[i][j]);
}

/**
 * renderMapGrid - Render the map grid to the screen
 */

void	renderMapGrid(void)
{
	int			tileX;
	int			tileY;
	uint32_t	tileColor;
	int i, j;

	for (i = 0; i < MAP_NUM_ROWS; i++)
	{
		for (j = 0; j < MAP_NUM_COLS; j++)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

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