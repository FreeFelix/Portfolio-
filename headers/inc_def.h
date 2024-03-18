#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>
#include <math.h>

/**
 * PI - Mathematical constant representing the value of pi
 */
#define PI 3.14159265

/**
 * TWO_PI - Mathematical constant representing the value of 2 * pi
 */
#define TWO_PI 6.28318530

/**
 * TILE_SIZE - Size of each tile in pixels
 */
#define TILE_SIZE 64

/**
 * NUM_TEXTURES - Number of available textures
 */
#define NUM_TEXTURES 14

/**
 * NUM_SPRITES - Number of available sprites
 */
#define NUM_SPRITES 6

/**
 * MINIMAP_SCALE_FACTOR - Scale factor for the minimap
 */
#define MINIMAP_SCALE_FACTOR 0.2

/**
 * WINDOW_WIDTH - Width of the game window
 */
#define WINDOW_WIDTH 1280

/**
 * WINDOW_HEIGHT - Height of the game window
 */
#define WINDOW_HEIGHT 720

/**
 * FOV_ANGLE - Field of view angle in radians
 */
#define FOV_ANGLE (60 * (PI / 180))

/**
 * NUM_RAYS - Number of rays for ray casting, equal to the window width
 */
#define NUM_RAYS WINDOW_WIDTH

/**
 * DIST_PROJ_PLANE - Distance to the projection plane
 */
#define DIST_PROJ_PLANE ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2))

/**
 * FPS - Frames per second
 */
#define FPS 30

/**
 * FRAME_TIME_LENGTH - Length of each frame in milliseconds
 */
#define FRAME_TIME_LENGTH (1000 / FPS)

/**
 * color_t - Type representing a color
 */
typedef uint32_t color_t;

#endif
