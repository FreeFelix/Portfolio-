#ifndef TEXTURES_H
#define TEXTURES_H

#include <stdint.h>
#include "inc_def.h"
#include "upng.h"

/**
 * textures - Array of texture pointers
 */
upng_t *textures[NUM_TEXTURES];

/**
 * loadTextures - Load textures from image files
 */
void loadTextures();

/**
 * freeTextures - Free memory allocated for textures
 */
void freeTextures();

#endif
