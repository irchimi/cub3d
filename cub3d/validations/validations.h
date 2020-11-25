#ifndef VALIDATIONS_H
# define VALIDATIONS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int     valid_open_file(char    *file_name);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(char *str);
int     valid_start_data(int count, char *params[]);

#endif