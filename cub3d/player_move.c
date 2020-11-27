#include "draw.h"

int     move(int keycode, t_setting *set)
{
    if (keycode == RIGHT)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.x++;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == LEFT)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.x--;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == UP)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.y--;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == DOWN)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.y++;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    return(0);
}