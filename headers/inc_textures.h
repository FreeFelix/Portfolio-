#ifndef TEXTURES_H
#define TEXTURES_H

#include <stdint.h>
#include "inc_def.h"
#include "upng.h"
/**
 * textures - Array of texture pointers
 */
upng_t *textures[NUM_TEXTURES];
void loadTextures(void);
void freeTextures(void);

#endif
