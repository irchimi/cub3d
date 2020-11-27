#ifndef DRAW_H
# define DRAW_H

#include "types.h"
#include <mlx.h>

# define START_MENU "doom_mega.xpm"

void        draw_start_menu(t_setting *set);
void        draw_game_win(t_setting *set);
void        clear_win(t_setting *set);
void        draw_mini_map(t_setting *set);
int         move(int keycode, t_setting *set);
void        draw_line_anover(int x, int y, int x_end, int y_end, t_setting *set);
void        draw_line_black(int x, int y, int x_end, int y_end, t_setting *set);
void        draw_line_red(int x, int y, int x_end, int y_end, t_setting *set);
void        draw_line_green(int x, int y, int x_end, int y_end, t_setting *set);
int         check_next_move(t_setting *set, int x_next, int y_next);
void        draw_angle(t_setting *set);
void        clear_angle(t_setting *set);

#endif