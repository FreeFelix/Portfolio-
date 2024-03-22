#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef uint32_t color_t;

bool initializeWindow(void);
void destroyWindow(void);
void clearColorBuffer(color_t color);
void renderColorBuffer(void);
void drawPixel(int x, int y, color_t color);

#endif /* GRAPHICS_H */
