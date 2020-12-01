#include "cub3d.h"
#include "draw.h"
#include <math.h>

void	perform(t_raicast_data *data)
{
	while (data->hit == 0)
		{
			if (data->side_dist_x < data->side_dist_y)
			{
				data->side_dist_x += data->delta_dist_x;
				data->map_x += data->step_x;
				data->side = 0;
			}
			else
			{
				data->side_dist_y += data->delta_dist_y;
				data->map_y += data->step_y;
				data->side = 1;
			}
			if (data->map[data->map_x][data->map_y] > 0) 
				data->hit = 1;
		}
}

void	init_side_dist(t_raicast_data *data)
{
	if (data->ray_dir_x < 0)
		{
			data->step_x = -1;
			data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
		}
		else
		{
			data->step_x = 1;
			data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
		}
		if (data->ray_dir_y < 0)
		{
			data->step_y = -1;
			data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
		}
		else
		{
			data->step_y = 1;
			data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
		}
}

void	calculate(t_raicast_data *data)
{
	int lineHeight;

	if (data->side == 0)
		data->wall_dist = (data->map_x - data->pos_x + (1 - data->step_x) / 2) / data->ray_dir_x;
	else
		data->wall_dist = (data->map_y - data->pos_y + (1 - data->step_y) / 2) / data->ray_dir_y;

	lineHeight = (int)(data->height / data->wall_dist);

	data->draw_start = -lineHeight / 2 + data->height  / 2;
	if(data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = lineHeight / 2 + data->height  / 2;
	if(data->draw_end >= data->height )
		data->draw_end = data->height  - 1;
}

void	raicast(t_raicast_data *data)
{
	int	x;

	x = 0;
	while (x < data->wid)
	{
		data->hit = 0;
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		data->camera_x = 2 * x / (double)data->wid - 1;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		data->delta_dist_x = my_abs(1 / data->ray_dir_x);
		data->delta_dist_y = my_abs(1 / data->ray_dir_y);	
		init_side_dist(data);
		perform(data);
		calculate(data);

		int	color;
		if (data->map[data->map_y][data->map_x] == 1)
			color = 0x00FF0000;
		else if (data->map[data->map_y][data->map_x] == 2)
			color = 0x0000FF00;
		else
			color = 0x000000FF;
		
		if (data->side == 1)
			color = color / 2;

		draw_frame(data, x, data->draw_start, data->draw_end, color);
		
		x++;
	}
}

int	main_loop(t_raicast_data *data)
{
	raicast(data);
	return (0);
}

void    draw_game_win(t_setting *set)
{
    t_raicast_data data;
    int i;
    int l;

	data.mlx = mlx_init();

    i = 0;
    l = 0;
    data.map = (int **)malloc(sizeof(int *) * 100);
    while (set->map.map[i])
    {
        data.map[i] = (int *)malloc(sizeof(int) * 100);
        i++;
    }
    i = 0;
    while (set->map.map[i])
    {
        while (set->map.map[i][l])
        {
            if (set->map.map[i][l] == ' ')
                data.map[i][l] = 4;
            if (set->map.map[i][l] == '1')
                data.map[i][l] = 1;
            if (set->map.map[i][l] == '0')
                data.map[i][l] = 0;
			if (set->map.map[i][l] == '2')
                data.map[i][l] = 2;
            printf("%d ", data.map[i][l]);
            l++;
        }
        printf("\n");
        l = 0;
        i++;
    }
	data.height = set->win.hight;
	data.wid = set->win.wid;
	data.pos_x = set->player.y;
	data.pos_y = set->player.x;
	data.dir_x = -1;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_y = 0.66;
	data.move_speed = 1;
	data.rot_speed = 0.5;
	
	data.win = mlx_new_window(data.mlx, data.wid, data.height, "kotorina");

	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, 2, 1L<<0,  &player_move, &data);

	mlx_loop(data.mlx);
}