#ifndef UTILS_H
#define UTILS_H

/**
 * normalizeAngle - Normalize an angle to the range [0, 2*PI)
 * @angle: Pointer to the angle to be normalized
 */
void normalizeAngle(float *angle);

/**
 * distanceBetweenPoints - Calculate the Euclidean distance between two points
 * @x1: The x-coordinate of the first point
 * @y1: The y-coordinate of the first point
 * @x2: The x-coordinate of the second point
 * @y2: The y-coordinate of the second point
 *
 * Returns:
 *   The Euclidean distance between the two points
 */
int distanceBetweenPoints(float x1, float y1, float x2, float y2);

#endif