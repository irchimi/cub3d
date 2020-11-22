#include "main.h"

int		main(int count, char *argv[])
{
	t_setting *set;

	if (valid_args(count, argv) == 1)
	{
		set = setting_inicializ(argv[1]);
		//char **result = reader_input_data(argv[1]);
		free(set);
	}
	return (0);
}
