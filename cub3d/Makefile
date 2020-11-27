# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeraldi <djeraldi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 13:33:50 by djeraldi          #+#    #+#              #
#    Updated: 2020/11/21 18:23:32 by djeraldi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 	cub3d.c \
		validations/ft_strncmp.c \
		validations/valid_start_data.c \
		validations/valid_open_file.c \
		validations/ft_strlen.c \
		errors/error_start_data.c \
		gnl.c \
		gnl_utils.c \
		reader.c \
		reader_data/reader_colors.c \
		reader_data/reader_sizes.c \
		reader_data/reader_textures.c \
		draw_start_menu.c \
		draw_utils.c \
		reader_data/ft_strnew.c \
		reader_data/ft_bzero.c \
		reader_data/reader_map.c \

OBJS = ${SRCS:.c=.o}

NAME = a.out

GCC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Imlx

%.o: %.c
	$(GCC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

INC=%%

INCLIB=$(INC)/../lib

${NAME}:	${OBJS}
			$(GCC)  ${OBJS} -o $(NAME) mlx_linux/libmlx.a -L$(INCLIB) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lbsd -lz

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
