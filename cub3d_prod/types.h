#ifndef TYPES_H
# define TYPES_H

# define ENTER 65293
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define A 97
# define D 100
# define BUFFER_SIZE 10
# define SOUND_START "/sound/start_sount.mp3"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_raicast_data
{
    int    height;
    int    wid;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	void	*mlx;
	void	*win;
	double	move_speed;
	double	rot_speed;
    int    **map;
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
	double side_dist_y;
    double delta_dist_x;
	double delta_dist_y;
	double wall_dist;
    int step_x;
	int step_y;
    int hit;
    int draw_start;
    int draw_end;
	int side; 
}				t_raicast_data;

typedef struct 	s_img
{
	void        *img;
    int         hight;
    int         wid;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}	            t_img;

typedef struct  s_win
{
    void        *mlx;
    void        *mlx_win;
    int         hight;
    int         wid;
    t_img       img;
}               t_win;

typedef struct  s_texture
{
    char        *path_sprite;
    char        *path_ea;
    char        *path_we;
    char        *path_no;
    char        *path_so;

    char        *ptr_so;
    char        *adr_so;
    //todo all texture
    int         valid_so;
    int         valid_no;
    int         valid_we;
    int         valid_ea;
    int         valid_sprite;
    int         valid_all;
}               t_texture;

typedef struct  s_sprite
{
    int                 x;
    int                 y;
    struct  s_sprite   *next;
}               t_sprite;


typedef struct  s_player
{
    int         x;
    int         y;
    int         x_next;
    int         y_next;
    int         count;
    int         valid;
    int         hp;
    int         lvl;
    int         exp;
    char        orientation;
}               t_player;


typedef struct  s_color
{
    int r;
    int g;
    int b;
}               t_color;


typedef struct  s_map
{
    char        **map;
    int         hight;
    int         wid;
    int         start_in_file;
    int         start;
    int         valid;
    char        *stat_data;
    int         def_size;
}               t_map;


typedef struct  s_setting
{
    t_map           map;
    t_player        player;
    t_texture       texture;
    t_win           win;
    t_color         floor;
    t_color         ceilling;
}               t_setting;


#endif