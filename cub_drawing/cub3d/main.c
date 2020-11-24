#include <mlx.h>
#include "main.h"

t_setting      *init_set()
{
    t_setting *set;

    set = (t_setting *)malloc(sizeof(t_setting) * 1);
    set->win_start.mlx = mlx_init();
    set->win_game.mlx = mlx_init();
    set->size_start.height = 600;
    set->size_start.width = 480;
    set->size.height = 1000;
    set->size.width = 1000;
    set->colors.ceilling.r = 255;
    set->colors.ceilling.g = 255;
    set->colors.ceilling.b = 255;
    set->colors.ceilling.r = 0;
    set->colors.ceilling.g = 0;
    set->colors.ceilling.b = 0;
    return (set);
}

void            clear(t_setting *set)
{
    int x;
    int y;

    x = 0;
    y = 0;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x < set->size.width)
    {
        while (y < set->size.height)
        {
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x00000000);
            y++;
        }
        y = 0;
        x++;
    }
}

void            draw_up_panel(t_setting *set)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x_end = set->size.width;
    y_end = set->size.height / 100;
    x = 0;
    y = 0;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x < x_end)
    {
        while (y < y_end)
        {
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x556B2F);
            y++;
        }
        y = 0;
        x++;
    }
}
void            draw_left_panel(t_setting *set)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x_end = set->size.width / 100;
    y_end = set->size.height;
    x = 0;
    y = 0;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x < x_end)
    {
        while (y < y_end)
        {
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x556B2F);
            y++;
        }
        y = 0;
        x++;
    }
}
void            draw_right_panel(t_setting *set)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x_end = set->size.width;
    y_end = set->size.height;
    x = set->size.width - set->size.width / 100;
    y = 0;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x < x_end)
    {
        while (y < y_end)
        {
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x556B2F);
            y++;
        }
        y = 0;
        x++;
    }
}

void            draw_game_panel(t_setting *set)
{
    draw_up_panel(set);
    draw_left_panel(set);
    draw_right_panel(set);

}

int             start_game(int keycode, t_setting *set)
{
    if (keycode == ENTER)
    {
        printf("%s\n", "start game...");
        clear(set);
        draw_game_panel(set);
        mlx_loop(set->win_start.mlx);
    }
    return (0);
}

void            draw_start_menu(t_setting *set)
{
    char    *relative_path = "menu_start.xpm";
    int     img_width;
    int     img_height;

    set->sound = 0;
    set->sound = fork();
    (set->sound == 0) ? system("mpg123 sound/start.mp3") : 0;
    set->win_start.mlx_win = mlx_new_window(set->win_start.mlx, set->size.width, set->size.height, "kotorina");
    set->img.img = mlx_xpm_file_to_image(set->win_start.mlx, relative_path, &img_width, &img_height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    mlx_put_image_to_window(set->win_start.mlx, set->win_start.mlx_win, set->img.img, 0, 0);
    mlx_hook(set->win_start.mlx_win, 2, 1L<<0, start_game, set);
    mlx_loop(set->win_start.mlx);
}


int             main()
{
    t_setting *set;

    set = init_set();
    draw_start_menu(set);
    mlx_loop(set->win_start.mlx);
    return (0);
}
