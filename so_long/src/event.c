#include "./../include/so_long.h"

int    wait_event(t_game *game)
{
    game->frame++;
    if (game->frame == ANIMATION)
    {
        ft_bzero((uint32_t *)game->img[0].pixels, TOTAL_PIXEL_COL * TOTAL_PIXEL_ROW);
        draw_new_image(game, 1);
        game->frame = 0;
    }
    return 0;
}