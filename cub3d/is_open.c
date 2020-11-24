#include "main.h"

int     is_open_file(char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (-1);
    return (1);
}