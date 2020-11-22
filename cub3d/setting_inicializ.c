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
		if (data_file[len][0] == 'R')
			printf("%s\n", data_file[len]);
		len++;
	}
	return (set);
}
