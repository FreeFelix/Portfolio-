#include "../headers/raycast.h"
#include "../headers/utilse.h"

ray_t	rays[NUM_RAYS];

/**
 * isRayFacingDown - Check if the ray is facing downward
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing downward, otherwise false
 */

bool	isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - Check if the ray is facing upward
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing upward, otherwise false
 */

bool	isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}

/**
 * isRayFacingRight - Check if the ray is facing right
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing right, otherwise false
 */

bool	isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - Check if the ray is facing left
 * @angle: The angle of the ray
 *
 * Returns:
 *   true if the ray is facing left, otherwise false
 */

bool	isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}