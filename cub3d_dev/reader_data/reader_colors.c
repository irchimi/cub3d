#include "reader_data.h"

t_setting   *reader_colors(t_setting *set, char *line)
{
    if (line[0] == 'F' && line[1] == ' ')
    {
        set->floor.r = 0;
        set->floor.g = 0;
        set->floor.b = 0;
    }
    if (line[0] == 'C' && line[1] == ' ')
    {
        set->ceilling.r = 0;
        set->ceilling.g = 0;
        set->ceilling.b = 0;
        set->map.start = 1;
    }
    return (set);
}