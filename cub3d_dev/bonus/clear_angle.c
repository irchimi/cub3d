#include "draw.h"

void        clear_angle(t_setting *set)
{
    if (set->player.orientation == 'N')
        clear_angle_N(set);
    if (set->player.orientation == 'S')
        clear_angle_S(set);
    if (set->player.orientation == 'E')
        clear_angle_E(set);
    if (set->player.orientation == 'W')
        clear_angle_W(set);
}

void        clear_angle_S(t_setting *set)
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
        y_dr = y_dr + 5;
        x++;
        y++;
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
        y_dr = y_dr + 5;
        count++;
        x--;
        y++;
    }
}

void    clear_angle_N(t_setting *set)
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

void        clear_angle_E(t_setting *set)
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
    x_dr = x * 5;
    y_dr = y * 5;
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
    x_dr = x * 5 + 15;
    y = set->player.y;
    y_dr = y * 5 + 15;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_black(x_dr - 9, y_dr - 5, x_dr - 6, y_dr, set);
        x_dr = x_dr + 5;
        y_dr = y_dr + 5;
        count++;
        x++;
        y++;
    }
}

void        clear_angle_W(t_setting *set)
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
    x_dr = x * 5;
    y_dr = y * 5;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_black(x_dr + 6, y_dr, x_dr + 9, y_dr + 5, set);
        x_dr = x_dr - 5;
        y_dr = y_dr - 5;
        x--;
        y--;
        count++;
    }
    count = 0;
    x = set->player.x;
    x_dr = x * 5 + 15;
    y = set->player.y;
    y_dr = y * 5 + 15;
    while (count < angle && set->map.map[y][x] != '1')
    {
        draw_line_black(x_dr - 9, y_dr - 5, x_dr - 6, y_dr, set);
        x_dr = x_dr - 5;
        y_dr = y_dr + 5;
        count++;
        x--;
        y++;
    }
}