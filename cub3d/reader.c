#include "cub3d.h"

t_setting   *init_data(char *file_name)
{
    t_setting   *set;

    set = (t_setting *)malloc(sizeof(t_setting));
    set->map.stat_data = "";
    set = reader_data(file_name, set);
    set->player.x = -1;
    set->player.y = -1;
    set = init_player(set);
    set->data_raicat.speed = 10;
    set->data_raicat.x_DR = -1;
    set->data_raicat.y_DR = 0;
    set->data_raicat.plane_x = 0;
    set->data_raicat.plane_Y = 0.66;
    return (set);
}

t_setting   *init_map(t_setting *set, char  **data)
{
    int i;
    int start;

    start = 0;
    i = 0;
    while (data[start][0] != '1' && data[start][0] != ' ')
        start++;
    while (i < (set->map.start - 1))
    {
        set->map.map[i] = data[start];
        i++;
        start++;
    }
    set->map.map[i] = NULL;
    return (set);
}

t_setting   *reader_data(char *file_name, t_setting *set)
{
    char        *line;
    int         file;
    char        *data;
    char        **data_split;

    file = open(file_name, O_RDONLY);
    if (file == -1)
        return (NULL);

    data = NULL;
    while (get_next_line(file, &line))
    {
        data = ft_strjoin(data, line);
        data = ft_strjoin(data, "\n");
        reader_sizes(set, line);
        reader_texture(set, line);
        reader_colors(set, line);
        reader_map(set, line);
    }
    data_split = ft_split(data, '\n');
    set->map.map = (char **)malloc(sizeof(char *) * (set->map.start + 1));
    set = init_map(set, data_split);
    free(data_split);
    free(line);
    return (set);
}