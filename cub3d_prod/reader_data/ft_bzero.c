#include "reader_data.h"

//thank Luke Medusa
//i love u
void	ft_bzero(void *str, size_t len)
{
	int				i;
	int				max;
	unsigned char	*src;

	max = (int)len;
	src = (unsigned char *)str;
	i = 0;
	while (i <= max - 1)
	{
		src[i] = '\0';
		i++;
	}
}