#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_display_sizes
{
	size_t	height;
	size_t	width;
}				t_display_sizes;

typedef struct			s_setting
{
	t_display_sizes		size;
	char				**map;
}						t_setting;

#endif
