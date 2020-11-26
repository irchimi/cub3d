#include "reader_data.h"

t_setting   *reader_sizes(t_setting *set, char *line)
{
    if (line[0] == 'R' && line[1] == ' ')
    {
        set->win.wid = 1000;
        set->win.hight = 1000;
    }
    return (set);
}