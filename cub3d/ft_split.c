#include "main.h"

static int			count(const char *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len);
}

static char			*ft_print(char *str, char c)
{
	int				len;
	char			*res;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len] && str[len] != c)
	{
		res[len] = str[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

static void			clean(char **res)
{
	free(res);
}

char				**ft_split(char const *s, char c)
{
	int				i;
	char			**res;

	i = 0;
	if (!s || (res = (char **)malloc(sizeof(char *) * (count(s, c) + 1))) == 0)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			res[i] = ft_print((char *)s, c);
			if (res[i] == NULL)
			{
				clean(res);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
