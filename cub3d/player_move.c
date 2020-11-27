#include "draw.h"

int     move(int keycode, t_setting *set)
{
    if (keycode == RIGHT && check_next_move(set, set->player.x + 1, set->player.y) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.x++;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == LEFT && check_next_move(set, set->player.x - 1, set->player.y) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.x--;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == UP && check_next_move(set, set->player.x, set->player.y - 1) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.y--;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == DOWN && check_next_move(set, set->player.x, set->player.y + 1) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        set->player.y++;
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    return(0);
}

int     check_next_move(t_setting *set, int x_next, int y_next)
{
    if (set->map.map[y_next][x_next] == '1')
        return (-1);
    return (1);
}