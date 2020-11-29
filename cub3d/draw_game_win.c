#include "cub3d.h"
#include "draw.h"
#include <math.h>

static  void    draw_frame(t_setting *set)
{

    
}

void    draw_game_win(t_setting *set)
{
    draw_mini_map(set);
    mlx_loop(set->win.mlx);
}