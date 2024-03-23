#ifndef SPRITE_H
#define SPRITE_H

#include "inc_def.h"
#include "inc_graphics.h"
#include "inc_player.h"
#include "inc_textures.h"

/**
 * @brief Structure representing a sprite in the game world
 */
typedef struct
{
	float	x;          /**< X-coordinate of the sprite */
	float	y;          /**< Y-coordinate of the sprite */
	float	distance;   /**< Distance of the sprite from the player */
	float	angle;      /**< Angle between the player's view direction and the sprite */
	bool	visible;    /**< Flag indicating if the sprite is currently visible */
	int		texture;    /**< Index of the texture associated with the sprite */
}	sprite_t;

/**
 * @brief Array of sprites in the game world
 */
void renderSpriteProjection(void);
void renderMapSprites(void);

#endif /* SPRITE_H */