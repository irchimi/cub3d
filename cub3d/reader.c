#include "main.h"

char		**reader_input_data(char *file_name)
{
	int file;
	char *result_in_one_line;
	char *line;
	char **result;

	file = open(file_name, O_RDONLY);
	result = NULL;
	result_in_one_line = NULL;
	if (file == -1)
	{
		return (error_read_file());
	}
	while (get_next_line(file, &line))
	{
		if (ft_strlen(line) == 0)
		{
			line = ft_strjoin(line, "-");
			line = ft_strjoin(line, "\t");
		}
		else
		{
			line = ft_strjoin(line, "\t");
		}
		result_in_one_line = ft_strjoin(result_in_one_line, line);
		free(line);
	}
	result = ft_split(result_in_one_line, '\t');
	if (result == NULL)
		return (error_read_file());
	return (result);
}
