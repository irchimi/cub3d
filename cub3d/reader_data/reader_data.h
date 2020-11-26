#ifndef READER_DATA_H
# define READER_DATA_H

#include "../types.h"

t_setting   *reader_sizes(t_setting *set, char *line);
t_setting   *reader_texture(t_setting *set, char *line);
t_setting   *reader_colors(t_setting *set, char *line);
//t_setting   *reader_map(t_setting *set, char *line);
#endif