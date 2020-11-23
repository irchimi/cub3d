#include "main.h"

static int		find_start(char *str, char c)
{
	int len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static int		find_end(char *str, char c)
{
	int len;
	int result;

	result = 0;
	len = 0;
	while (str[len])
	{
		if (str[len] == c)
			result = len;
		len++;
	}
	return (result);
}

t_setting		*setting_inicializ(char *file_name)
{
	t_setting *set;
	int len;
	char **data_file;

	len = 0;
	set = (t_setting *)malloc((sizeof(t_setting)));
	data_file = reader_input_data(file_name);
	while (data_file[len])
	{
		set = switch_set_size(data_file[len], set);
		set = switch_set_texture(data_file[len], set);
		set = switch_set_color(data_file[len], set);
		set = switch_set_map(data_file[len], set, len, data_file);
		len++;
	}
	return (set);
}

t_setting		*switch_set_texture(char *line, t_setting *set)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		set->texture.no = ft_substr(line, find_start(line, '.'), ft_strlen(line) - find_start(line, '.'));
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		set->texture.so = ft_substr(line, find_start(line, '.'), ft_strlen(line) - find_start(line, '.'));
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		set->texture.we = ft_substr(line, find_start(line, '.'), ft_strlen(line) - find_start(line, '.'));
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		set->texture.ea = ft_substr(line, find_start(line, '.'), ft_strlen(line) - find_start(line, '.'));
	if (line[0] == 'S' && line[1] == ' ')
		set->texture.sprite = ft_substr(line, find_start(line, '.'), ft_strlen(line) - find_start(line, '.'));
	return (set);
}

t_setting		*switch_set_size(char *line, t_setting *set)
{
	char	*tmp;
	if (line[0] == 'R' && line[1] == ' ')
	{
		tmp = ft_substr(line, find_start(line, ' '), find_end(line, ' ') - find_start(line, ' '));
		set->size.height = ft_atoi(tmp);
		free(tmp);
		tmp = ft_substr(line,  find_end(line, ' '), ft_strlen(line) - find_end(line, ' '));
		set->size.width = ft_atoi(tmp);
		free(tmp);
	}
	return (set);
}


t_setting		*switch_set_color(char *line, t_setting *set)
{
	char	*tmp;

	if (line[0] == 'F' && line[1] == ' ')
	{
		tmp = ft_substr(line, find_start(line, ' '), find_start(line, ',') - find_start(line, ' '));
		set->colors.floor.r = ft_atoi(tmp);
		free(tmp);
		tmp = ft_substr(line, find_start(line, ',') + 1, find_end(line, ',') - find_start(line, ','));
		set->colors.floor.g = ft_atoi(tmp);
		free(tmp);
		tmp = ft_substr(line, find_end(line, ',') + 1, ft_strlen(line) - find_end(line, ','));
		set->colors.floor.b = ft_atoi(tmp);
		free(tmp);
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		tmp = ft_substr(line, find_start(line, ' '), find_start(line, ',') - find_start(line, ' '));
		set->colors.ceilling.r = ft_atoi(tmp);
		free(tmp);
		tmp = ft_substr(line, find_start(line, ',') + 1, find_end(line, ',') - find_start(line, ','));
		set->colors.ceilling.g = ft_atoi(tmp);
		free(tmp);
		tmp = ft_substr(line, find_end(line, ',') + 1, ft_strlen(line) - find_end(line, ','));
		set->colors.ceilling.b = ft_atoi(tmp);
		free(tmp);
		set->map.flag_map = 1;
	}
	return (set);
}

t_setting		*switch_set_map(char *line, t_setting *set, int iter, char **data)
{
	int count;
	int i_cpy;

	i_cpy = (iter + 1);
	count = 0;
	if (set->map.flag_map == 1 && line)
	{
		set->map.flag_map = 2;
		set->map.start_map = iter;
	}
	if (set->map.flag_map == 2)
	{
		set->map.len = count_len_map(data, iter);
		if (!(set->map.map = (char **)malloc(sizeof(char *) * (set->map.len + 1))))
			return (error_malloc());
		while (count < (set->map.len - 1))
		{
			if (data[i_cpy][0] == '1' || data[i_cpy][0] == '0' || data[i_cpy][0] == ' ')
			{
				set->map.map[count] = data[i_cpy];
				count++;
			}
			i_cpy++;
		}
		set->map.map[count] = NULL;
		set->map.flag_map = 3;
	}
	return (set);
}

int 		count_len_map(char **data, int iter)
{
	int len;
	int flag_error;

	flag_error = 0;
	len = 0;
	while (data[iter])
	{
		if ((data[iter][0] == '1' || data[iter][0] == '0' || data[iter][0] == ' ') && (flag_error == 0 || flag_error == 1))
		{
			len++;
			flag_error = 1;
		}
		if (!(data[iter][0] == '1' || data[iter][0] == '0' || data[iter][0] == ' ') && len >= 1)
		{
			flag_error = 2;
			return (error_map());
		}
		iter++;
	}
	if (len != 0)
		len++;
	return (len);
}
