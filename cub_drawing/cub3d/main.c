#include <mlx.h>
#include "main.h"

t_setting      *init_set()
{
    t_setting *set;

    set = (t_setting *)malloc(sizeof(t_setting) * 1);
    set->mlx = mlx_init();
    set->size.height = 600;
    set->size.width = 480;
    set->colors.ceilling.r = 255;
    set->colors.ceilling.g = 255;
    set->colors.ceilling.b = 255;
    set->colors.ceilling.r = 0;
    set->colors.ceilling.g = 0;
    set->colors.ceilling.b = 0;
    return (set);
}

void            draw_start_menu(t_setting *set)
{
    char    *relative_path = "menu_start.xpm";
    int     img_width;
    int     img_height;

    set->sound = 0;
    set->sound = fork();
    (set->sound == 0) ? system("mpg123 sound/start.mp3") : 0;
    set->img.img = mlx_xpm_file_to_image(set->mlx, relative_path, &img_width, &img_height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    mlx_put_image_to_window(set->mlx, set->mlx_win, set->img.img, 0, 0);
    mlx_loop(set->mlx);
}

int             main()
{
    t_setting *set;

    set = init_set();
    set->mlx_win = mlx_new_window(set->mlx, set->size.width, set->size.height, "kotorina");
    draw_start_menu(set);
    mlx_loop(set->mlx);
    free(set->mlx_win);
    return (0);
}