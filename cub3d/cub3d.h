#ifndef CUB3D_H
# define CUB3D_H

#include "types.h"
#include "validations/validations.h"
#include "errors/errors.h"
#include "reader_data/reader_data.h"
#include "draw/draw.h"

void		*ft_memmove(void *dst, const void *src, size_t len);
int		    get_next_line(int fd, char **line);
t_setting   *init_data(char *file_name);
t_setting   *read_size(t_setting *set, char *line);
char		*ft_strjoin(char const *s1, char const *s2);
t_setting   *reader_data(char *file_name, t_setting *set);

#endif