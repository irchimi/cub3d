#include "draw.h"

void		player_move_up(t_raicast_data *data)
{
	clear_win_game(data);
	if (!data->map[(int)(data->pos_x + data->dir_x * data->move_speed)][(int)(data->pos_y)])
		data->pos_x += data->dir_x * data->move_speed;
	if (!data->map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * data->move_speed)])
		data->pos_y += data->dir_y * data->move_speed;
}

void		player_move_down(t_raicast_data *data)
{
	clear_win_game(data);
	if (!data->map[(int)(data->pos_x - data->dir_x * data->move_speed)][(int)(data->pos_y)])
		data->pos_x -= data->dir_x * data->move_speed;
	if (!data->map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y * data->move_speed)])
		data->pos_y -= data->dir_y * data->move_speed;
}

void		player_move_right(t_raicast_data *data)
{
	double old_dir_x;
	double old_plane_x;

	clear_win_game(data);
	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rot_speed) - data->dir_y * sin(-data->rot_speed);
	data->dir_y = old_dir_x * sin(-data->rot_speed) + data->dir_y * cos(-data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->rot_speed) - data->plane_y * sin(-data->rot_speed);
	data->plane_y = old_plane_x * sin(-data->rot_speed) + data->plane_y * cos(-data->rot_speed);
}

void		player_move_left(t_raicast_data *data)
{
	double old_dir_x;
	double old_plane_x;

	clear_win_game(data);
	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed) - data->dir_y * sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) + data->dir_y * cos(data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y * sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) + data->plane_y * cos(data->rot_speed);
}

int			player_move(int key, t_raicast_data *data)
{
	printf("%d\n", key);
	printf("%f  -  %f\n", data->pos_x, data->pos_y);
	if (key == UP)
		player_move_up(data);
	if (key == DOWN)
		player_move_down(data);
	if (key == RIGHT)
		player_move_right(data);
	if (key == LEFT)
		player_move_left(data);
	return (0);
}