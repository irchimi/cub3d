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
    set->size.width = 1800;
    set->colors.ceilling.r = 255;
    set->colors.ceilling.g = 255;
    set->colors.ceilling.b = 255;
    set->colors.ceilling.r = 0;
    set->colors.ceilling.g = 0;
    set->colors.ceilling.b = 0;
    set->texture.ea_path = "wall.xpm";
    set->texture.no_path = "wall.xpm";
    set->texture.we_path = "wall.xpm";
    set->texture.so_path = "wall.xpm";

    int map[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
    //set->map.map = map;
    return (set);
}

void            init_textur(t_setting *set)
{
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    set->texture.north_ptr = mlx_xpm_file_to_image(set->win_start.mlx, set->texture.no_path, set->texture.width, set->texture.height);
    set->texture.north_adr = mlx_get_data_addr(set->texture.north_ptr, set->texture.bits_per_pixel, set->texture.line_length, set->texture.endian);
    set->texture.south_ptr = mlx_xpm_file_to_image(set->win_start.mlx, set->texture.so_path, set->texture.width, set->texture.height);
    set->texture.south_adr = mlx_get_data_addr(set->texture.south_ptr, set->texture.bits_per_pixel, set->texture.line_length, set->texture.endian);
    set->texture.west_ptr = mlx_xpm_file_to_image(set->win_start.mlx, set->texture.we_path, set->texture.width, set->texture.height);
    set->texture.west_adr = mlx_get_data_addr(set->texture.west_ptr, set->texture.bits_per_pixel, set->texture.line_length, set->texture.endian);
    set->texture.east_ptr= mlx_xpm_file_to_image(set->win_start.mlx, set->texture.ea_path, set->texture.width, set->texture.height);
    set->texture.east_adr = mlx_get_data_addr(set->texture.east_ptr, set->texture.bits_per_pixel, set->texture.line_length, set->texture.endian);
}

void            draw_some(int x, int y, int x_end, int y_end, int smx, int smy, t_setting *set)
{
    int x_c;
    int y_c;

    x_c = x;
    y_c = y;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x_c < x_end)
    {
        while (y_c < y_end)
        {
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x_c, y_c, 0x2F4F4F);
            y_c += smy;
        }
        y_c = y;
        x_c += smx;
    }
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
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x2F4F4F);
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
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x2F4F4F);
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
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x2F4F4F);
            y++;
        }
        y = 0;
        x++;
    }
}

void            draw_down_panel(t_setting *set)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x_end = set->size.width;
    y_end = set->size.height;
    x = 0;
    y = set->size.height - (set->size.height / 8);
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
        y = set->size.height - (set->size.height / 8);
        x++;
    }
}

void            draw_up_split(t_setting *set)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x = 0;
    x_end = set->size.width;
    y = set->size.height - set->size.height / 8;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x < x_end)
    {
        mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x2F4F4F);
        mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y + 1, 0x2F4F4F);
        mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y + 2, 0x2F4F4F);
        mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y + 3, 0x2F4F4F);
        mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y + 4, 0x2F4F4F);
        x++;
    }
}

void            draw_splits(t_setting *set)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x = 0;
    y = set->size.height - set->size.height / 8;
    y_end = set->size.height;
    x_end = set->size.width;
    set->img.img = mlx_new_image(set->win_start.mlx, set->size.width, set->size.height);
    set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length,
                                 &set->img.endian);
    while (x < x_end)
    {
        while (y < y_end)
        {
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 1, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 2, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 3, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 4, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 5, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 6, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 7, y, 0x2F4F4F);
            mlx_pixel_put(set->win_start.mlx, set->win_start.mlx_win, x + 8, y, 0x2F4F4F);
            y++;
        }
        y = set->size.height - (set->size.height / 8);
        x += set->size.width / 5;
    }
    draw_up_split(set);
}

void            draw_player(t_setting *set)
{
    int y;
    char    *relative_path = "player.xpm";
    int     img_width;
    int     img_height;
    t_img   img;

    img.img = mlx_xpm_file_to_image(set->win_start.mlx, relative_path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    int x = set->size.width / 2 - (img_width / 2);
    y = set->size.height - set->size.height / 8;
    mlx_put_image_to_window(set->win_start.mlx, set->win_start.mlx_win, img.img, x, y);
    draw_some(x - 5, y, x, set->size.height, 1, 1, set);
    draw_some(x + img_width, y, x + img_width + 5, set->size.height, 1, 1, set);
}

void            draw_HP(t_setting *set)
{
    int x;
    int y;

    x = (set->size.width / 5) + 50;
    y = set->size.height - (set->size.height / 8) + 20;
    draw_some(x, y, x + 10, set->size.height - 10, 1, 1, set);
}

void            draw_health_bar(t_setting *set)
{
    draw_player(set);
    draw_splits(set);
    draw_HP(set);
}

void            draw_game_panel(t_setting *set)
{
    draw_up_panel(set);
    draw_left_panel(set);
    draw_right_panel(set);
    draw_down_panel(set);
    draw_health_bar(set);
    init_textur(set);
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
    char    *relative_path = "doom_mega.xpm";
    int     img_width;
    int     img_height;

    set->sound = 0;
    //set->sound = fork();
    //(set->sound == 0) ? system("mpg123 sound/start.mp3") : 0;
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
