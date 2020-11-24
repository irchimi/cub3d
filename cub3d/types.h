#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_display_sizes
{
	int	height;
	int	width;
}				t_display_sizes;

typedef struct	s_texture
{
	char 		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sprite;
}				t_texture;

typedef	struct		s_sprite
{
	int				x;
	int				y;
	struct s_sprite	*next;
}					t_sprite;

typedef struct	s_player
{
	int			x;
	int 		y;
	char		direction;
}				t_player;

typedef struct  s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct s_colors_map
{
	t_color floor;
	t_color ceilling;
}				t_colors_map;

typedef	struct	s_map
{
	char		**map;
	int			len;
	int			flag_map;
	int			start_map;
}				t_map;

typedef struct 	s_img
{
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_img;

typedef struct			s_setting
{
	t_display_sizes		size; 
	t_texture			texture;
	t_player			player;
	t_sprite			*sprite;
	t_colors_map		colors;
	t_map				map;
	void				*mlx;
	void				*mlx_win;
	t_img				img;
}						t_setting;

#endif
