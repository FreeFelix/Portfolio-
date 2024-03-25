#include "../headers/wall.h"

/**
 * changeColorIntensity - Change the color intensity
 * based on factor value between 0 and 1
 * @color: Pointer to the color value
 * @factor: Factor value between 0 and 1
 *
 * Description: This function modifies the intensity of
 * a given color based on the provided factor.
 */

void	changeColorIntensity(color_t *color, float factor)
{
	color_t	a;
	color_t	r;
	color_t	g;
	color_t	b;

	a = (*color & 0xFF000000);
	r = (*color & 0x00FF0000) * factor;
	g = (*color & 0x0000FF00) * factor;
	b = (*color & 0x000000FF) * factor;

	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}
/**
 * renderWallProjection - Render the wall projection
 *
 * Description: This function renders the projected walls
 * on the screen based on the raycasting technique.
 */
void	renderWallProjection(void)
{
	float		distanceProjPlane;
	float		wallHeight;
	int			wallTopY;
	int			wallBottomY;
	float		perpDistance;
	color_t		texelColor;
	color_t		*wallTextureBuffer;
	int			textureOffsetX;
	int			textureOffsetY;
	int			distanceFromTop;
	int			texNum;
	int			textureWidth;
	int			textureHeight;

	for (int x = 0; x < NUM_RAYS; x++)
	{
		distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		perpDistance = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle);
		wallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;
		wallTopY = (WINDOW_HEIGHT / 2) - (wallHeight / 2);
		wallTopY = wallTopY < 0 ? 0 : wallTopY;
		wallBottomY = (WINDOW_HEIGHT / 2) + (wallHeight / 2);
		wallBottomY = wallBottomY > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomY;

		for (int y = 0; y < wallTopY; y++)
			drawPixel(x, y, 0xFF444444);

		if (rays[x].wasHitVertical)
			textureOffsetX = (int)rays[x].wallHitY % TILE_SIZE;
		else
			textureOffsetX = (int)rays[x].wallHitX % TILE_SIZE;

		texNum = rays[x].texture - 1;
		textureWidth = upng_get_width(textures[texNum]);
		textureHeight = upng_get_height(textures[texNum]);

		for (int y = wallTopY; y < wallBottomY; y++)
		{
			distanceFromTop = y + (wallHeight / 2) - (WINDOW_HEIGHT / 2);
			textureOffsetY = distanceFromTop * ((float)textureHeight / wallHeight);
			wallTextureBuffer = (color_t *)upng_get_buffer(textures[texNum]);
			texelColor = wallTextureBuffer[(textureWidth * textureOffsetY) + textureOffsetX];

			if (rays[x].wasHitVertical)
				changeColorIntensity(&texelColor, 0.7);

			drawPixel(x, y, texelColor);
		}

		for (int y = wallBottomY; y < WINDOW_HEIGHT; y++)
			drawPixel(x, y, 0xFF777777);
	}
}