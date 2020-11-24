#include "main.h"

static int check_valid_texture(t_setting *set)
{
    if (is_open_file(set->texture.ea) && is_open_file(set->texture.no) && is_open_file(set->texture.so)
    && is_open_file(set->texture.sprite) && is_open_file(set->texture.we))
        return (1);
    return (error_open_texture());
}

static int check_valid_size(t_setting *set)
{
    if (set->size.height > 2000 || set->size.width > 2000)
        return(error_size());
    return (1);
}

static int check_valid_map(t_setting *set)
{
    if (set->map.map)
        return (1);
    return (0);
}

int     check_valid_set(t_setting *set)
{
    if (check_valid_map(set) && check_valid_size(set) && check_valid_texture(set))
        return (1);
    return (0);
}