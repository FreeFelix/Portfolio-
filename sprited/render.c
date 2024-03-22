#include "graphics_rendering.h"

/**
 * drawRect - Draw a rectangle with the specified dimensions and color
 * @x: The x-coordinate of the top-left corner of the rectangle
 * @y: The y-coordinate of the top-left corner of the rectangle
 * @width: The width of the rectangle
 * @height: The height of the rectangle
 * @color: The color of the rectangle
 */
void drawRect(int x, int y, int width, int height, color_t color)
{
	for (int i = x; i <= (x + width); i++)
	{
		for (int j = y; j < (y + height); j++)
		{
			drawPixel(i, j, color);
		}
	}
}

/**
 * drawLine - Draw a line between two points with the specified color
 * @x0: The x-coordinate of the starting point of the line
 * @y0: The y-coordinate of the starting point of the line
 * @x1: The x-coordinate of the ending point of the line
 * @y1: The y-coordinate of the ending point of the line
 * @color: The color of the line
 */
void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	int deltaX;
	int deltaY;
	int longestSideLength;
	float xIncrement;
	float yIncrement;
	float currentX;
	float currentY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);
	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);
	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;
	currentX = x0;
	currentY = y0;

	for (int i = 0; i < longestSideLength; i++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}