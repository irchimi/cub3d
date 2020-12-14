# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rin <rin@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 13:33:50 by djeraldi          #+#    #+#              #
#    Updated: 2020/12/15 02:12:19 by rin              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 	cub3d.c \
		gnl.c \
		gnl_utils.c \
		reader.c \

OBJS = ${SRCS:.c=.o}

NAME = a.out

GCC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Imlx

%.o: %.c
	$(GCC)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
