#include "validations.h"

int     valid_open_file(char    *file_name)
{
    int file;

    file = open(file_name, O_RDONLY);
    if (file == -1)
        return (-1);
    return (1);
}