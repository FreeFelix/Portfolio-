#include "../headers/definition.h"
#include "../headers/textures.h"

static const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
};

/**
 * wallTextures - Array to store wall textures.
 * Description:
 * This array holds the textures for different types of walls. Each
 * element of the array represents a different texture.
 */
texture_t wallTextures[NUM_TEXTURES];

/**
 * WallTexturesready - Load textures into the respective position.
 * Description:
 * This function loads textures from files specified in textureFileNames
 * into the wallTextures array. It initializes the texture properties such
 * as width, height, and texture buffer.
 * Return: No return value.
 */
void WallTexturesready(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[i]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[i].upngTexture = upng;
				wallTextures[i].width = upng_get_width(upng);
				wallTextures[i].height = upng_get_height(upng);
				wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}
}

/**
 * freeWallTextures - Free wall textures.
 * Description:
 * This function frees the memory allocated for the wall textures stored
 * in the wallTextures array.
 * Return: No return value.
 */
void freeWallTextures(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
		upng_free(wallTextures[i].upngTexture);
}
