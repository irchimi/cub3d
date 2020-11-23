#include "errors.h"
#include <stdio.h>

int		error_input_data()
{
	printf("%s\n", "Error:\n Not valid input data!");
	return (1);
}


int		error_open_file()
{
	printf("%s\n", "Error:\n Can not open file!");
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
	return (0);
}

t_setting	*error_malloc()
{
	printf("%s\n", "Error:\n Can not malloc!");
	return (0);
}
