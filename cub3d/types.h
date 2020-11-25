#ifndef TYPES_H
# define TYPES_H

# define BUFFER_SIZE 1
# define SOUND_START "/sound/start_sount.mp3"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_win
{
    void        *mlx;
    void        *mlx_win;
    int         hight;
    int         wid;
    int         sound;
}               t_win;

typedef struct  s_texture
{
    char        *path_ea;
    char        *path_we;
    char        *path_no;
    char        *path_so;

    char        *ptr_so;
    char        *adr_so;
    //todo all texture
    int         valid_so;
    int         valid_no;
    int         valid_we;
    int         valid_ea;
    int         valid_all;
}               t_texture;

typedef struct  s_player
{
    int         x;
    int         y;
    int         count;
    int         valid;
    int         hp;
    int         lvl;
    int         exp;
}               t_player;


typedef struct  s_map
{
    char        *map;
    int         hight;
    int         wid;
    int         start_in_file;
    int         valid;
}               t_map;


typedef struct  s_setting
{
    t_map       map;
    t_player    player;
    t_texture   texture;
    t_win       win;
}               t_setting;


#endif