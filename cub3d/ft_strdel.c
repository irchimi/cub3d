#include "cub3d.h"

//thank Luke Medusa
//i love u
void	ft_strdel(char **s)
{
	if (s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}