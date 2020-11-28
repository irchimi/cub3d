#include "cub3d.h"
#include "draw.h"


static  void    draw_frame(t_setting *set)
{
    int len;
    int vector;

    
}

void    draw_game_win(t_setting *set)
{
    draw_mini_map(set);
    mlx_loop(set->win.mlx);
}