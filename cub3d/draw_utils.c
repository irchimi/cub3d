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