#include "draw.h"
#include "../mlx_linux/mlx.h"

void        draw_start_menu(t_setting *set)
{
    set->win.mlx_win = mlx_new_window(set->win.mlx, set->win.wid, set->win.hight, "KotoRina");
    mlx_loop(set->win.mlx);
}