#ifndef GRAPHICS_H
#define GRAPHICS_H

// #include <stdint.h>
#include <stdint.h> // Add this line to include the stdint.h header
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "inc_def.h"

/**
 * initializeWindow - Initialize the game window
 *
 * Returns:
 *   true if window initialization is successful, otherwise false
 */
bool initializeWindow(void);

/**
 * destroyWindow - Destroy the game window and clean up resources
 */
void destroyWindow(void);

/**
 * clearColorBuffer - Clear the color buffer with the specified color
 * @color: The color to clear the buffer with
 */
void clearColorBuffer(color_t color);

/**
 * renderColorBuffer - Render the color buffer to the screen
 */
void renderColorBuffer(void);

/**
 * drawPixel - Draw a pixel at the specified coordinates with the specified color
 * @x: The x-coordinate of the pixel
 * @y: The y-coordinate of the pixel
 * @color: The color of the pixel
 */
void drawPixel(int x, int y, color_t color);

/**
 * drawRect - Draw a rectangle with the specified dimensions and color
 * @x: The x-coordinate of the top-left corner of the rectangle
 * @y: The y-coordinate of the top-left corner of the rectangle
 * @width: The width of the rectangle
 * @height: The height of the rectangle
 * @color: The color of the rectangle
 */
void drawRect(int x, int y, int width, int height, color_t color);

/**
 * drawLine - Draw a line between two points with the specified color
 * @x0: The x-coordinate of the starting point of the line
 * @y0: The y-coordinate of the starting point of the line
 * @x1: The x-coordinate of the ending point of the line
 * @y1: The y-coordinate of the ending point of the line
 * @color: The color of the line
 */
void drawLine(int x0, int y0, int x1, int y1, color_t color);

#endif
