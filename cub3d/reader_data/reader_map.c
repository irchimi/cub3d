#include "reader_data.h"

t_setting       *reader_map(t_setting *set, char *line)
{
    if (set->map.start != 0)
    {
        if (ft_strlen(line) >= 1 && (line[0] == '1' || line[0] == ' ') && ft_strncmp(line, "", ft_strlen(line)) != 0)
        {
            //set->map.stat_data = ft_strjoin(set->map.stat_data, line);
            printf("%s\n", line);
        }
    }
    return (set);
}