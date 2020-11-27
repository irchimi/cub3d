#include "draw.h"

/*
void        draw_angle(t_setting *set)
{
    int x;
    int y;
    int max_angle;
    int count;
    int x_dr;
    int y_dr;

    count = 0;
    max_angle = 25;
    x = set->player.x;
    y = set->player.y;
    x_dr = x * 5;
    y_dr = y * 5;
    if (set->player.orientation = 'N')
    {
        while (count < max_angle && set->map.map[y][x] != '1')
        {
            draw_line_anover(x_dr + 6, y_dr , x_dr + 9, y_dr + 5, set);
            count++;
            y--;
            y_dr -= 5;
        }
        y = set->player.y;
        y_dr = y * 5;
        count = 0;
        while (count < max_angle && set->map.map[y][x] != '1')
        {
            draw_line_anover(x_dr + 10, y_dr + 6, x_dr + 15, y_dr + 9, set);
            count++;
            x++;
            x_dr += 5;
        }
    }
}
*/

void        draw_angle(t_setting *set)
{
    int x;
    int y;
    int x_dr;
    int y_dr;
    int count;
    int angle;

    count = 0;
    angle = 20;
    x = set->player.x;
    y = set->player.y;
    x_dr = x * 5 + 5;
    y_dr = y * 5 + 5;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_anover(x_dr + 6, y_dr, x_dr + 9, y_dr + 5, set);
        x_dr = x_dr + 5;
        y_dr = y_dr - 5;
        x++;
        y--;
        count++;
    }
    count = 0;
    x = set->player.x;
    x_dr = x * 5 + 10;
    y = set->player.y;
    y_dr = y * 5 + 10;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_anover(x_dr - 9, y_dr - 5, x_dr - 6, y_dr, set);
        x_dr = x_dr - 5;
        y_dr = y_dr - 5;
        count++;
        x--;
        y--;
    }
}

void    clear_angle(t_setting *set)
{
    int x;
    int y;
    int x_dr;
    int y_dr;
    int count;
    int angle;

    count = 0;
    angle = 20;
    x = set->player.x;
    y = set->player.y;
    x_dr = x * 5 + 5;
    y_dr = y * 5 + 5;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_black(x_dr + 6, y_dr, x_dr + 9, y_dr + 5, set);
        x_dr = x_dr + 5;
        y_dr = y_dr - 5;
        x++;
        y--;
        count++;
    }
    count = 0;
    x = set->player.x;
    x_dr = x * 5 + 10;
    y = set->player.y;
    y_dr = y * 5 + 10;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_black(x_dr - 9, y_dr - 5, x_dr - 6, y_dr, set);
        x_dr = x_dr - 5;
        y_dr = y_dr - 5;
        count++;
        x--;
        y--;
    }
}
