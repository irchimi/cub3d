#include "main.h"
#include <mlx.h>

/*
static void	draw_menu(t_setting *set)
{
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	mlx_pixel_put(set->mlx, set->mlx_win, 10, 1000, 0x0000FF00);
}
*/

static void draw_contors_down(t_setting *set)
{
	int x_start;
	int x_end;
	int y_start;
	int y_end;

	x_start = 0;
	x_end = set->size.width;
	y_start = set->size.height - (set->size.height / 10);
	y_end = set->size.height;
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	while (x_start < x_end)
	{
		while (y_start < y_end)
		{
			mlx_pixel_put(set->mlx, set->mlx_win, x_start, y_start, 0x00AAFFF0);
			y_start++;
		}
		y_start = set->size.height - (set->size.height / 10);
		x_start++;
	}
}

static void	draw_contors_up(t_setting *set)
{
	int x_start;
	int x_end;
	int y_start;
	int y_end;

	x_start = 0;
	x_end = set->size.width;
	y_start = 0;
	y_end = set->size.height / 40;
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	while (x_start < x_end)
	{
		while (y_start < y_end)
		{
			mlx_pixel_put(set->mlx, set->mlx_win, x_start, y_start, 0x00AAFFF0);
			y_start++;
		}
		y_start = 0;
		x_start++;
	}
}

static void draw_contors_left(t_setting *set)
{
	int x_start;
	int x_end;
	int y_start;
	int y_end;

	x_start = 0;
	x_end = set->size.width / 100;
	y_start = 0;
	y_end = set->size.height;
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	while (x_start < x_end)
	{
		while (y_start < y_end)
		{
			mlx_pixel_put(set->mlx, set->mlx_win, x_start, y_start, 0x00AAFFF0);
			y_start++;
		}
		y_start = 0;
		x_start++;
	}
}

static void draw_contors_right(t_setting *set)
{
	int x_start;
	int x_end;
	int y_start;
	int y_end;

	x_start = set->size.width - (set->size.width / 100);
	x_end = set->size.width;
	y_start = 0;
	y_end = set->size.height;
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	while (x_start < x_end)
	{
		while (y_start < y_end)
		{
			mlx_pixel_put(set->mlx, set->mlx_win, x_start, y_start, 0x00AAFFF0);
			y_start++;
		}
		y_start = 0;
		x_start++;
	}
}

static void draw_contors_slash_line(t_setting *set)
{
	int x_start;
	int x_end;
	int y_start;
	int y_end;

	x_start = 1;
	x_end = set->size.width;
	y_start = set->size.height - (set->size.height / 40);
	y_end = set->size.height;
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	while (x_start < x_end)
	{
		while (y_start < y_end)
		{
			mlx_pixel_put(set->mlx, set->mlx_win, x_start, y_start, 0x0AAAAAA0);
			mlx_pixel_put(set->mlx, set->mlx_win, x_start+1, y_start, 0x0AAAAAA0);
			mlx_pixel_put(set->mlx, set->mlx_win, x_start+2, y_start, 0x0AAAAAA0);
			mlx_pixel_put(set->mlx, set->mlx_win, x_start+3, y_start, 0x0AAAAAA0);
			y_start++;
		}
		y_start = set->size.height - (set->size.height / 10);
		x_start += set->size.width / 5;
	}
}

static void draw_contour_slash(t_setting *set)
{
		int x_start;
	int x_end;
	int y_start;
	int y_end;

	x_start = 0;
	x_end = set->size.width;
	y_start = set->size.height - (set->size.height / 10);
	y_end = set->size.height - (set->size.height / 10) + 10;
	set->img.img = mlx_new_image(set->mlx, set->size.width, set->size.height);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	while (x_start < x_end)
	{
		while (y_start < y_end)
		{
			mlx_pixel_put(set->mlx, set->mlx_win, x_start, y_start, 0x0AAAAAA0);
			y_start++;
		}
		y_start = set->size.height - (set->size.height / 10);
		x_start ++;
	}
}

int		main(int count, char *argv[])
{
	t_setting *set;

	set = NULL;
	if (valid_args(count, argv) == 1)
		set = setting_inicializ(argv[1]);
	if (check_valid_set(set) == 1)
	set->mlx = mlx_init();
	set->mlx_win = mlx_new_window(set->mlx, set->size.width, set->size.height, "cub3d - kotorina");
	draw_contors_down(set);
	draw_contors_up(set);
	draw_contors_left(set);
	draw_contors_right(set);
	draw_contors_slash_line(set);
	draw_contour_slash(set);
	mlx_loop(set->mlx);
	free(set);
	return (0);
}