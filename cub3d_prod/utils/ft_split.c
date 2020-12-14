#include "cub3d.h"

//thank Luke Medusa
//i love u
static size_t	ft_numword(char const *s, char c)
{
	size_t			i;
	size_t			word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);
}

static size_t	ft_lenword(char const *s, char c)
{
	size_t			i;
	size_t			len;

	i = 0;
	len = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

void			ft_leak(char **res, size_t i)
{
	while (i)
		ft_strdel(&res[--i]);
	free(res);
}

char			**ft_split(char const *s, char c)
{
	char			**res;
	size_t			i;
	size_t			k;
	unsigned int	j;

	i = -1;
	j = 0;
	if (!s || !(res = (char **)malloc(sizeof(char *) * ft_numword(s, c) + 1)))
		return (NULL);
	while (++i < ft_numword(s, c))
	{
		k = 0;
		while (s[j] == c)
			j++;
		if (!(res[i] = ft_strnew(ft_lenword(&s[j], c))))
		{
			ft_leak(res, i);
			return (NULL);
		}
		while (s[j] != c && s[j])
			res[i][k++] = s[j++];
	}
	res[i] = NULL;
	return (res);
}