#include "../headers/draw.h"
#include "../headers/definition.h"

/**
 * drawRect - Draw a rectangle.
 * @x: X coordinate of the top-left corner.
 * @y: Y coordinate of the top-left corner.
 * @width: Width of the rectangle.
 * @height: Height of the rectangle.
 * @color: Color of the rectangle.
 *
 * Description: This function draws a rectangle on the screen
 * with the specified top-left corner coordinates, width, and
 * height, filled with the given color.
 *
 * Return: No return value.
 */

void drawRect(int x, int y, int width, int height, color_t color)
{
	int i, j;

	for (i = x; i <= (x + width); i++)
		for (j = y; j <= (y + height); j++)
			drawPixel(i, j, color);
}

/**
 * drawLine - Draw a line.
 * @x0: X coordinate of the starting point.
 * @y0: Y coordinate of the starting point.
 * @x1: X coordinate of the ending point.
 * @y1: Y coordinate of the ending point.
 * @color: Color of the rectangle.
 *
 * Description: This function draws a line on the screen from the starting
 * point to the ending point with the specified color.
 *
 * Return: No return value.
 */

void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	float xIncrement, yIncrement, currentX, currentY;
	int i, longestSideLength, deltaX,  deltaY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	currentX = x0;
	currentY = y0;

	for (i = 0; i < longestSideLength; i++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}
