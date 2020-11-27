#include "cub3d.h"

static int count_hight(t_setting *set)
{
    int len;

    len = 0;
    while (set->map.map[len])
        len++;
    return (len);
}

static int count_wid(t_setting *set)
{
    int len;
    int count;
    int len_max;

    count = 0;
    len = 0;
    len_max = 0;
    while (set->map.map[count])
    {
        len = ft_strlen(set->map.map[count]);
        if (len > len_max)
            len_max = len;
        count++;
    }
    return (len_max);
}

void    draw_mini_map(t_setting *set)
{
    int x;
    int y;
    int x_dr;
    int y_dr;

    x = 0;
    y = 0;
    x_dr = 5;
    y_dr = 5;
    while (set->map.map[y])
    {
        while (set->map.map[y][x])
        {
            if (set->map.map[y][x] == '1')
                draw_line_green(x_dr, y_dr, x_dr + 5, y_dr + 5, set);
            x++;
            x_dr += 5;
        }
        x = 0;
        x_dr = 5;
        y++;
        y_dr += 5;
    }
    draw_line_red(set->player.x * 5 + 5, set->player.y * 5 + 5, set->player.x * 5 + 10, set->player.y * 5 + 10, set);
    mlx_hook(set->win.mlx_win, 2, 1L<<0, move, set);
    mlx_loop(set->win.mlx);
}