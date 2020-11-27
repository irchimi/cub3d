#include "cub3d.h"

t_setting   *init_data(char *file_name)
{
    t_setting   *set;

    set = (t_setting *)malloc(sizeof(t_setting));
    set->map.stat_data = "";
    set = reader_data(file_name, set);

    return (set);
}

t_setting   *reader_data(char *file_name, t_setting *set)
{
    char        *line;
    int         file;

    file = open(file_name, O_RDONLY);
    if (file == -1)
        return (NULL);

    while (get_next_line(file, &line))
    {
        reader_sizes(set, line);
        reader_texture(set, line);
        reader_colors(set, line);
        reader_map(set, line);
    }
    free(line);
    return (set);
}