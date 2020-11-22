#include "main.h"

static	int is_open(char *file_name)
{
	int file;

	file = open(file_name, O_RDONLY);
	return (file);
}

int		valid_args(int count, char *params[])
{

	if (count >= 4 || count <= 1)
		return (error_input_data());
	if (count == 2 && is_open(params[1]) >= 0)
	{
		return (1);
	}
	if (count == 2 && is_open(params[1]) == -1)
		return (error_open_file());

	/* TODO!!
	if (count == 3)
	{
		printf("%s\n", "map ok save ok");
		return (0);
	}
	if (count == 3 && params[2] != "--save")
	{
		return (error_input_data());
	}
	*/
	return (-1);
}
