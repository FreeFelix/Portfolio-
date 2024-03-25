#ifndef TEXTURES_H
#define TEXTURES_H

#include <stdint.h>
#include "definitions.h"
#include "upng.h"

upng_t	*textures[NUM_TEXTURES];

void	loadTextures();
void	freeTextures();

#endif
