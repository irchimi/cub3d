#include "draw.h"

int     move(int keycode, t_setting *set)
{
    /*
    if (keycode = A)
    {
        clear_angle(set);
        if (set->player.orientation == 'N')
            set->player.orientation = 'W';
        else
        {
            if (set->player.orientation == 'W')
                set->player.orientation = 'S';
            else
            {
                if (set->player.orientation == 'S')
                    set->player.orientation = 'E';
                else
                {
                    if (set->player.orientation == 'E')
                        set->player.orientation = 'N';
                }
            }
        }
        set->map.map[set->player.y][set->player.x] = set->player.orientation;
        draw_angle(set);
    }
    if (keycode = D)
    {
        clear_angle(set);
        if (set->player.orientation == 'N')
            set->player.orientation = 'E';
        else
        {
            if (set->player.orientation == 'E')
                set->player.orientation = 'S';
            else
            {
                if (set->player.orientation == 'S')
                    set->player.orientation = 'W';
                else
                {
                    if (set->player.orientation == 'W')
                        set->player.orientation = 'N';
                }
            }
        }
        set->map.map[set->player.y][set->player.x] = set->player.orientation;
        draw_angle(set);
    }
    */
    if (keycode == RIGHT && check_next_move(set, set->player.x + 1, set->player.y) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        clear_angle(set);
        set->player.x++;
        draw_angle(set);
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == LEFT && check_next_move(set, set->player.x - 1, set->player.y) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        clear_angle(set);
        set->player.x--;
        draw_angle(set);
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == UP && check_next_move(set, set->player.x, set->player.y - 1) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        clear_angle(set);
        set->player.y--;
        draw_angle(set);
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
    if (keycode == DOWN && check_next_move(set, set->player.x, set->player.y + 1) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        clear_angle(set);
        set->player.y++;
        draw_angle(set);
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