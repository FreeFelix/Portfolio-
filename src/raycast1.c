#include "../headers/definition.h"
#include "../headers/ray.h"

/**
 * distanceBetweenPoints - Calculate the distance between two points.
 * @x1: X coordinate of the first point.
 * @y1: Y coordinate of the first point.
 * @x2: X coordinate of the second point.
 * @y2: Y coordinate of the second point.
 * Return: The distance between the two points.
 */

float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

/**
 * isRayFacingDown - Check if the ray is facing downward.
 * @angle: Current angle of the ray.
 * Return: True if the ray is facing downward, otherwise false.
 */

bool isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - Check if the ray is facing upward.
 * @angle: Current angle of the ray.
 * Return: True if the ray is facing upward, otherwise false.
 */

bool isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}

/**
 * isRayFacingRight - Check if the ray is facing to the right.
 * @angle: Current angle of the ray.
 * Return: True if the ray is facing to the right, otherwise false.
 */

bool isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - Check if the ray is facing to the left.
 * @angle: Current angle of the ray.
 * Return: True if the ray is facing to the left, otherwise false.
 */

bool isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}

