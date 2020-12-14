#include "cub3d.h"


static int			ft_get_result(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_save_remainder(char *save)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(result = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		result[len++] = save[i++];
	result[len] = '\0';
	free(save);
	return (result);
}

static char	*ft_get_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*save;
	int				r;

	r = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_get_result(save) && r != 0)
	{
		if ((r = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[r] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	*line = ft_get_line(save);
	save = ft_save_remainder(save);
	if (r == 0)
		return (0);
	return (1);
}