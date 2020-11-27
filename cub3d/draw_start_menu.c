#include "draw.h"

int         start_game(int keycode, t_setting *set)
{
    if (keycode == ENTER)
    {
        printf("%s\n", "start game...");
        clear_win(set);
        draw_mini_map(set);
        //draw_game_win(set);
        mlx_loop(set->win.mlx);
    }
    return (0);
}

void        draw_start_menu(t_setting *set)
{
    char    *relative_path = "texture/doom_mega.xpm";
    int     img_width;
    int     img_height;

    set->win.mlx = mlx_init();
    set->win.mlx_win = mlx_new_window(set->win.mlx, set->win.wid, set->win.hight, "KotoRina");
    set->win.img.img = mlx_xpm_file_to_image(set->win.mlx, relative_path, &img_width, &img_height);
    set->win.img.addr = mlx_get_data_addr(set->win.img.img, &set->win.img.bits_per_pixel, &set->win.img.line_length,
                                 &set->win.img.endian);
    mlx_put_image_to_window(set->win.mlx, set->win.mlx_win, set->win.img.img, 0, 0);
    mlx_hook(set->win.mlx_win, 2, 1L<<0, start_game, set);
    mlx_loop(set->win.mlx);
}