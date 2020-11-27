#include "reader_data.h"

//thank Luke Medusa
//i love u
char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}