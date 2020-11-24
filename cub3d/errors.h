#ifndef ERRORS_H
# define ERRORS_H

#include "types.h"
int			error_input_data();
int			error_open_file();
int			error_map();
char		**error_read_file();
t_setting	*error_malloc();
int 		error_open_texture();
int			error_size();

#endif
