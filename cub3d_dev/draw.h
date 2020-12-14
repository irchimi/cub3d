#ifndef DRAW_H
# define DRAW_H

#include "types.h"
#include <mlx.h>
#include <math.h>

# define START_MENU "doom_mega.xpm"

//void        draw_start_menu(t_setting *set);
void        draw_game_win(t_setting *set);
void		player_move_up(t_raicast_data *data);
void		player_move_down(t_raicast_data *data);
void		player_move_right(t_raicast_data *data);
void		player_move_left(t_raicast_data *data);
int			player_move(int key, t_raicast_data *data);
void        clear_win_game(t_raicast_data *set);
void	    draw_frame(t_raicast_data *data, int x, int y_srart, int y_end, int color);
double	    my_abs(double x);
/*
void        clear_win(t_setting *set);
void        draw_mini_map(t_setting *set);
int         move(int keycode, t_setting *set);
void        draw_line_anover(int x, int y, int x_end, int y_end, t_setting *set);
void        draw_line_black(int x, int y, int x_end, int y_end, t_setting *set);
void        draw_line_red(int x, int y, int x_end, int y_end, t_setting *set);
void        draw_line_green(int x, int y, int x_end, int y_end, t_setting *set);
int         check_next_move(t_setting *set, int x_next, int y_next);
void        draw_angle(t_setting *set);
void        draw_angle_N(t_setting *set);
void        draw_angle_S(t_setting *set);
void        draw_angle_E(t_setting *set);
void        draw_angle_W(t_setting *set);
void        clear_angle(t_setting *set);
void        clear_angle_N(t_setting *set);
void        clear_angle_S(t_setting *set);
void        clear_angle_W(t_setting *set);
void        clear_angle_E(t_setting *set);
void        move_in_map(t_setting *set, char c);
*/
#endif