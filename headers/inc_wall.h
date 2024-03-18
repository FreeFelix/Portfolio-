#ifndef WALL_H
#define WALL_H

#include <math.h>
#include "inc_def.h"
#include "inc_player.h"
#include "inc_ray.h"
#include "inc_graphics.h"
#include "inc_textures.h"

/**
 * renderWallProjection - Render the projection of walls onto the screen
 */
void renderWallProjection(void);

/**
 * changeColorIntensity - Change the intensity of a color by the specified factor
 * @color: Pointer to the color to be modified
 * @factor: The factor by which to change the intensity
 */
void changeColorIntensity(color_t *color, float factor);

#endif
