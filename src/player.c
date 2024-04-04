#include "../headers/definition.h"
#include "../headers/player.h"

player_t newPlayer;

/**
 * setPlayerPosition - Sets the position of the new player.
 * @x: X-coordinate of the new player.
 * @y: Y-coordinate of the new player.
 * 
 * Return: No return value.
 */
void setPlayerPosition(float x, float y) {
    newPlayer.x = x;
    newPlayer.y = y;
}

/**
 * movePlayer - Sets the next position of the player.
 * @DeltaTime: Time elapsed since the last frame.
 * 
 * Return: No return value.
 */
void movePlayer(float DeltaTime)
{
    float moveStep, newPlayerX, newPlayerY;

    player.rotationAngle += player.turnDirection * player.turnSpeed * DeltaTime;
    moveStep = player.walkDirection * player.walkSpeed * DeltaTime;

    newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
    newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

    if (!DetectCollision(newPlayerX, newPlayerY))
    {
        player.x = newPlayerX;
        player.y = newPlayerY;
    }
}

/**
 * renderPlayer - Renders the player.
 * 
 * Return: No return value.
 */
void renderPlayer(void)
{
    drawRect(
        player.x * MINIMAP_SCALE_FACTOR,
        player.y * MINIMAP_SCALE_FACTOR,
        player.width * MINIMAP_SCALE_FACTOR,
        player.height * MINIMAP_SCALE_FACTOR,
        0xFFFFFFFF
    );
    
    /* Render the new player*/
    drawRect(
        newPlayer.x * MINIMAP_SCALE_FACTOR,
        newPlayer.y * MINIMAP_SCALE_FACTOR,
        newPlayer.width * MINIMAP_SCALE_FACTOR,
        newPlayer.height * MINIMAP_SCALE_FACTOR,
        0xFF00FF00 /* Example color for the new player */
    );
}