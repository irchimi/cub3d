#include "main.h"

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
		set = switch_setting(data_file[len], set, len);
		printf("%s\n", data_file[len]);
		len++;
	}
	return (set);
}

t_setting		*switch_setting(char *line, t_setting *set, int iter)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		set->size.width = 1900;
		set->size.height = 1900;
	}
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		set->texture.no = "";
	}
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		set->texture.so = "";
	}
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		set->texture.we = "";
	}
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		set->texture.ea = "";
	}
	if (line[0] == 'S' && line[1] == ' ')
	{
		set->texture.sprite = "";
	}
	if (line[0] == 'F' && line[1] == ' ')
	{
	set->texture.sprite = "";
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		set->texture.sprite = "";
		set->flag_map = 1;
	}
	if (set->flag_map == 1 && set->start_map == 0 && line)
	{
		set->flag_map = 2;
		set->start_map = iter;
	}
	return (set);
}
