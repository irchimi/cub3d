#include "errors.h"
#include <stdio.h>

int		error_input_data()
{
	printf("%s\n", "Error:\n Not valid input data!");
	exit(1);
	return (1);
}


int		error_open_file()
{
	printf("%s\n", "Error:\n Can not open file!");
	exit(2);
	return (2);
}

int		error_map()
{
	printf("%s\n", "Error:\n Not valid map!");
	exit(3);
	return (3);
}

char		**error_read_file()
{
	printf("%s\n", "Error:\n Can not read file!");
	exit(0);
	return (0);
}

t_setting	*error_malloc()
{
	printf("%s\n", "Error:\n Can not malloc!");
	exit(0);
	return (0);
}

int 		error_open_texture()
{
	printf("%s\n", "Error:\n Not valid texture!");
	exit(4);
	return (4);
}

int			error_size()
{
	printf("%s\n", "Error:\n Not valid size!");
	exit(5);
	return (5);
}
