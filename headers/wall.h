#ifndef WALL_H
#define WALL_H

#include <math.h>
#include "definitions.h"
#include "player.h"
#include "raycast.h"
#include "graphics.h"
#include "textures.h"

void	renderWallProjection(void);
void	changeColorIntensity(color_t *color, float factor);

#endif
