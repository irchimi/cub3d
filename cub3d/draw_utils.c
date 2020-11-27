#include "cub3d.h"

void    clear_win(t_setting *set)
{
    int x;
    int y;

    x = 0;
    y = 0;
    set->win.img.img = mlx_new_image(set->win.mlx, set->win.wid, set->win.hight);
    set->win.img.addr = mlx_get_data_addr(set->win.img.img, &set->win.img.bits_per_pixel, &set->win.img.line_length,
                                 &set->win.img.endian);
    while (x < set->win.wid)
    {
        while (y < set->win.hight)
        {
            mlx_pixel_put(set->win.mlx, set->win.mlx_win, x, y, 0x000000);
            y++;
        }
        x++;
        y = 0;
    }
}

void    draw_line(int x, int y, int x_end, int y_end, t_setting *set)
{
    int y_c;

    y_c = y;
    set->win.img.img = mlx_new_image(set->win.mlx, set->win.wid, set->win.hight);
    set->win.img.addr = mlx_get_data_addr(set->win.img.img, &set->win.img.bits_per_pixel, &set->win.img.line_length,
                                 &set->win.img.endian);
    while (x < x_end)
    {
        while (y < y_end)
        {
            mlx_pixel_put(set->win.mlx, set->win.mlx_win, x, y, 0x2F4F4F);
            y++;
        }
        x++;
        y = y_c;
    }
}