#include "reader_data.h"

t_setting   *reader_texture(t_setting *set, char *line)
{
    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        set->texture.path_no = line;
    if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        set->texture.path_so = line;
    if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        set->texture.path_we = line;
    if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        set->texture.path_ea = line;
    if (line[0] == 'S' && line[1] == ' ')
        set->texture.path_sprite = line;
    return (set);
}