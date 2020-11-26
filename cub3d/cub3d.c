#include <mlx.h>
#include "cub3d.h"
#include "types.h"

int main(int count, char *params[])
{
    t_setting *set;

    if (valid_start_data(count, params) == -1)
        return (error_start_data());
    set = init_data(params[1]);
    set->win.mlx = mlx_init();
    draw_start_menu(set);
    return (0);
}