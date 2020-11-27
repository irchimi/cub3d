#include "draw.h"

int     move(int keycode, t_setting *set)
{
    if (keycode == A)
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
    
    if (keycode == D)
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
    if (keycode == RIGHT)
        move_in_map(set, 'R');
    if (keycode == LEFT)
        move_in_map(set, 'L');
    if (keycode == UP)
        move_in_map(set, 'U');
    if (keycode == DOWN)
        move_in_map(set, 'D');
    
    return(0);
}

void    move_in_map(t_setting *set, char c)
{
    set->player.x_next = set->player.x;
    set->player.y_next = set->player.y;
    if (c == 'U')
    {
        if (set->player.orientation == 'N')
            set->player.y_next--;
        if (set->player.orientation == 'S')
            set->player.y_next++;
        if (set->player.orientation == 'W')
            set->player.x_next--;
        if (set->player.orientation == 'E')
            set->player.x_next++;
    }
    if (c == 'D')
    {
        if (set->player.orientation == 'N')
            set->player.y_next++;
        if (set->player.orientation == 'S')
            set->player.y_next--;
        if (set->player.orientation == 'W')
            set->player.x_next++;
        if (set->player.orientation == 'E')
            set->player.x_next--;
    }
    if (c == 'L')
    {
        if (set->player.orientation == 'N')
            set->player.x_next--;
        if (set->player.orientation == 'S')
            set->player.x_next++;
        if (set->player.orientation == 'W')
            set->player.y_next++;
        if (set->player.orientation == 'E')
            set->player.y_next--;
    }
    if (c == 'R')
    {
        if (set->player.orientation == 'N')
            set->player.x_next++;
        if (set->player.orientation == 'S')
            set->player.x_next--;
        if (set->player.orientation == 'W')
            set->player.y_next--;
        if (set->player.orientation == 'E')
            set->player.y_next++;
    }
    if (check_next_move(set, set->player.x_next, set->player.y_next) == 1)
    {
        draw_line_black(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
        clear_angle(set);
        set->player.x = set->player.x_next;
        set->player.y = set->player.y_next;
        draw_angle(set);
        draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    }
}

int     check_next_move(t_setting *set, int x_next, int y_next)
{
    if (set->map.map[y_next][x_next] == '1')
        return (-1);
    return (1);
}