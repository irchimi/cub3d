#include "validations.h"

int     valid_start_data(int count, char *params[])
{
    if (count == 2 && valid_open_file(params[1]))
        return (1);
    if (count == 3 && valid_open_file(params[1]) && (ft_strncmp(params[2], "--save", ft_strlen(params[2])) == 0))
        return (1);
    return (-1);
}