#include "../headers/definition.h"
#include "../headers/wall.h"
#include <math.h>

/**
 * changeColorIntensity - Changes the intensity of a color based on a
 * factor value between 0 and 1.
 * @factor: Intensity factor.
 * @color: Color for intensity adjustment.
 * Description: This function adjusts the intensity of the given color by
 * multiplying its RGB components
 * with the specified factor.
 * Return: None.
 */

void changeColorIntensity(color_t *color, float factor)
{
	color_t a = (*color & 0xFF000000);
	color_t r = (*color & 0x00FF0000) * factor;
	color_t g = (*color & 0x0000FF00) * factor;
	color_t b = (*color & 0x000000FF) * factor;

	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}

/**
 * renderFloor - Renders the floor projection.
 * @wallBottomPixel: Wall bottom pixel.
 * @texelColor: Texture color for the current pixel.
 * @x: Current element in the rays array.
 * Description: This function renders the floor projection for a given
 * ray by calculating the distance
 * to the floor and mapping the corresponding texture.
 * Return: None.
 */

void renderFloor(int wallBottomPixel, color_t *texelColor, int x)
{
	int y, texture_height, texture_width, textureOffsetY, textureOffsetX;
	float distance, ratio;

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = wallBottomPixel - 1; y < SCREEN_HEIGHT; y++)
	{
		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = (ratio * PROJ_PLANE) / cos(rays[x].rayAngle -
		player.rotationAngle);

		textureOffsetY = (int)(fabs((distance * sin(rays[x].rayAngle)) + player.y));
		textureOffsetX = (int)(fabs((distance * cos(rays[x].rayAngle)) + player.x));

		textureOffsetX = (textureOffsetX * texture_width / 30) % texture_width;
		textureOffsetY = (textureOffsetY * texture_height / 30) % texture_height;

		*texelColor = wallTextures[4].texture_buffer[(texture_width * textureOffsetY)
		+ textureOffsetX];
		drawPixel(x, y, *texelColor);
	}
}

/**
 * renderCeil - Renders the ceiling projection.
 * @wallTopPixel: Wall top pixel.
 * @texelColor: Texture color for the current pixel.
 * @x: Current element in the rays array.
 * Description: This function renders the ceiling projection for a
 * given ray by calculating the distance
 * to the ceiling and mapping the corresponding texture.
 * Return: None.
 */

void renderCeil(int wallTopPixel, color_t *texelColor, int x)
{
	int y, texture_width, texture_height, textureOffsetY, textureOffsetX;

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = wallTopPixel; y >= 0; y--)
	{
		float ratio = player.height / (SCREEN_HEIGHT / 2 - y);
		float distance = (ratio * PROJ_PLANE) / cos(rays[x].rayAngle -
		player.rotationAngle);

		textureOffsetY = (int)(fabs((-distance * sin(rays[x].rayAngle)) + player.y));
		textureOffsetX = (int)(fabs((-distance * cos(rays[x].rayAngle)) + player.x));

		textureOffsetX = (textureOffsetX * texture_width / 30) % texture_width;
		textureOffsetY = (textureOffsetY * texture_height / 30) % texture_height;

		*texelColor = wallTextures[4].texture_buffer[(texture_width *
		textureOffsetY) + textureOffsetX];
		drawPixel(x, y, *texelColor);
	}
}

/**
 * renderWall - Renders the wall projection.
 * Description: This function renders the wall projection by calculating
 * the height of the wall strip, mapping the corresponding texture,
 * and adjusting the intensity for shaded areas
 * Return: None.
 */

void renderWall(void)
{
	int x, y, texNum, texture_width, texture_height,
	    textureOffsetX, wallBottomPixel, wallStripHeight,
	    wallTopPixel, distanceFromTop, textureOffsetY;
	float perpDistance, projectedWallHeight;
	color_t texelColor;

	for (x = 0; x < NUM_RAYS; x++)
	{
		perpDistance = rays[x].distance * cos(rays[x].rayAngle
				- player.rotationAngle);
		projectedWallHeight = (TILE_SIZE / perpDistance) * PROJ_PLANE;
		wallStripHeight = (int)projectedWallHeight;
		wallTopPixel = (SCREEN_HEIGHT / 2) - (wallStripHeight / 2);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		wallBottomPixel = (SCREEN_HEIGHT / 2) + (wallStripHeight / 2);
		wallBottomPixel = wallBottomPixel > SCREEN_HEIGHT
			? SCREEN_HEIGHT : wallBottomPixel;
		texNum = rays[x].wallHitContent - 1;
		texture_width = wallTextures[texNum].width;
		texture_height = wallTextures[texNum].height;
		renderFloor(wallBottomPixel, &texelColor, x);
		renderCeil(wallTopPixel, &texelColor, x);

		if (rays[x].wasHitVertical)
			textureOffsetX = (int)rays[x].wallHitY % TILE_SIZE;
		else
			textureOffsetX = (int)rays[x].wallHitX % TILE_SIZE;

		for (y = wallTopPixel; y < wallBottomPixel; y++)
		{
			distanceFromTop = y + (wallStripHeight / 2) - (SCREEN_HEIGHT / 2);
			textureOffsetY = distanceFromTop *
				((float)texture_height / wallStripHeight);
			texelColor = wallTextures[texNum].
				texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
			if (rays[x].wasHitVertical)
				changeColorIntensity(&texelColor, 0.5);
			drawPixel(x, y, texelColor);
		}
	}
}
