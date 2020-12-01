#include "reader_data.h"

t_setting   *reader_sizes(t_setting *set, char *line)
{
    if (line[0] == 'R' && line[1] == ' ')
    {
        set->win.wid = 1800;
        set->win.hight = 1200;
    }
    return (set);
}