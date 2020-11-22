#ifndef MAIN_H
# define MAIN_H

# include "types.h"
# include "errors.h"
# define BUFFER_SIZE 1

int			valid_args(int count, char *params[]);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**reader_input_data(char *file_name);
char		**ft_split(char const *s, char c);
t_setting	*setting_inicializ(char *file_name);
t_setting	*switch_setting(char *line, t_setting *set, int iter);

#endif
