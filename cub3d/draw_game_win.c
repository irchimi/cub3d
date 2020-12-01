#include "cub3d.h"
#include "draw.h"
#include <math.h>

double	my_abs(double x)
{
	if (x < 0)
		return (x * (-1));
	return (x);
}

void	draw_frame(t_raicast_data *data, int x, int y_srart, int y_end, int color)
{
	int	y;

	y = y_srart;
	while (y <= y_end)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		y++;
	}
}

void    clear_win_game(t_raicast_data *set)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < set->wid)
    {
        while (y < set->height )
        {
            mlx_pixel_put(set->mlx, set->win, x, y, 0x000000);
            y++;
        }
        x++;
        y = 0;
    }
}

void	perform(t_raicast_data *data)
{
	while (data->hit == 0)
		{
			if (data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				data->side = 0;
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				data->side = 1;
			}
			if (data->map[data->mapX][data->mapY] > 0) 
				data->hit = 1;
		}
}

void	init_side_dist(t_raicast_data *data)
{
	if (data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX = 1;
			data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
		}
}

void	calculate(t_raicast_data *data)
{
	int lineHeight;

	if (data->side == 0)
		data->perpWallDist = (data->mapX - data->posX + (1 - data->stepX) / 2) / data->rayDirX;
	else
		data->perpWallDist = (data->mapY - data->posY + (1 - data->stepY) / 2) / data->rayDirY;

	lineHeight = (int)(data->height / data->perpWallDist);

	data->drawStart = -lineHeight / 2 + data->height  / 2;
	if(data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = lineHeight / 2 + data->height  / 2;
	if(data->drawEnd >= data->height )
		data->drawEnd = data->height  - 1;
}

void	raicast(t_raicast_data *data)
{
	int	x;

	x = 0;
	while (x < data->wid)
	{
		data->hit = 0;
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;
		data->cameraX = 2 * x / (double)data->wid - 1;
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		data->deltaDistX = my_abs(1 / data->rayDirX);
		data->deltaDistY = my_abs(1 / data->rayDirY);	
		init_side_dist(data);
		perform(data);
		calculate(data);

		int	color;
		if (data->map[data->mapY][data->mapX] == 1)
			color = 0x00FF0000;
		else if (data->map[data->mapY][data->mapX] == 2)
			color = 0x0000FF00;
		else
			color = 0x000000FF;
		
		if (data->side == 1)
			color = color / 2;

		draw_frame(data, x, data->drawStart, data->drawEnd, color);
		
		x++;
	}
}

int	main_loop(t_raicast_data *data)
{
	raicast(data);
	return (0);
}

int			player_move(int key, t_raicast_data *data)
{
	printf("%d\n", key);
	printf("%f  -  %f\n", data->posX, data->posY);
	if (key == UP)
	{
		clear_win_game(data);
		if (!data->map[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX += data->dirX * data->moveSpeed;
		if (!data->map[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)])
			data->posY += data->dirY * data->moveSpeed;
	}
	if (key == DOWN)
	{
		clear_win_game(data);
		if (!data->map[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX -= data->dirX * data->moveSpeed;
		if (!data->map[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)])
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (key == RIGHT)
	{
		clear_win_game(data);
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		double oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
        
	}
	if (key == LEFT)
	{
		clear_win_game(data);
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		double oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
        
	}
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
	data.posX = set->player.y;
	data.posY = set->player.x;
	data.dirX = -1;
	data.dirY = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	data.moveSpeed = 1;
	data.rotSpeed = 0.5;
	
	data.win = mlx_new_window(data.mlx, data.wid, data.height, "kotorina");

	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, 2, 1L<<0,  &player_move, &data);

	mlx_loop(data.mlx);
}