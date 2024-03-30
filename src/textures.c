#include "../headers/textures.h"
#include <stdio.h>

/*  textures - Array of texture pointers */
static const char*	textureFileNames[NUM_TEXTURES] =
{
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
	"./images/pikuma.png",
	"./images/barrel.png",
	"./images/light.png",
	"./images/table.png",
	"./images/guard.png",
	"./images/armor.png"
};

/**
 * loadTextures - Load textures from image files
 */

void	loadTextures(void)
{
	int i;
	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_t*	upng;

		upng = upng_new_from_file(textureFileNames[i]);
		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				textures[i] = upng;
			}
			else
			{
				printf("Error decoding texture file %s \n", textureFileNames[i]);
			}
		}
		else
		{
			printf("Error loading texture %s \n", textureFileNames[i]);
		}
	}

}

/**
 * freeTextures - Free memory allocated for textures
 */

void	freeTextures(void)
{
	int i;
	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_free(textures[i]);
	}
}
