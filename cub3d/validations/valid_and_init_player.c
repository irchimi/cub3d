#include "validations.h"

static int     is_in_line(char *line, char c)
{
    int len;

    len = 0;
    while (line[len] != '\0' && line[len] != c)
        len++;
    if (len == (int)ft_strlen(line))
        return (0);
    return (len);
}

t_setting       *init_player(t_setting *set)
{
    int     y;

    y = 0;
    while (y < (set->map.start - 1))
    {
        if (is_in_line(set->map.map[y], 'N') != 0)
        {
            if (set->player.x != -1)
            {
                printf("%s\n", "ERROR : \n Map error!");
                exit(1);
            }
            set->player.x = is_in_line(set->map.map[y], 'N');
            set->player.y = y;
            set->player.orientation = 'N';
        }
        if (is_in_line(set->map.map[y], 'W') != 0)
        {
            if (set->player.x != -1)
            {
                printf("%s\n", "ERROR : \n Map error!");
                exit(1);
            }
            set->player.x = is_in_line(set->map.map[y], 'W');
            set->player.y = y;
            set->player.orientation = 'W';
        }
        if (is_in_line(set->map.map[y], 'S') != 0)
        {
            if (set->player.x != -1)
            {
                printf("%s\n", "ERROR : \n Map error!");
                exit(1);
            }
            set->player.x = is_in_line(set->map.map[y], 'S');
            set->player.y = y;
            set->player.orientation = 'S';
        }
        if (is_in_line(set->map.map[y], 'E') != 0)
        {
            if (set->player.x != -1)
            {
                printf("%s\n", "ERROR : \n Map error!");
                exit(1);
            }
            set->player.x = is_in_line(set->map.map[y], 'E');
            set->player.y = y;
            set->player.orientation = 'E';
        }
        y++;
    }
    return (set);
}