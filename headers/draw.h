#ifndef DRAW_H
#define DRAW_H

#include "definition.h"
#include <math.h>
#include "player.h"
#include "ray.h"
#include "draw.h"
#include "textures.h"

#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

/* Functions-variables-structs for draw */

bool initializeWindow(void);
void destroyWindow(void);
void clearColorBuffer(color_t color);
void render_game(void);
void renderColorBuffer(void);
void drawPixel(int x, int y, color_t color);
void drawRect(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);

#endif /* DRAW_H */

