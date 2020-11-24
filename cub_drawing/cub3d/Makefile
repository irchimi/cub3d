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


SRCS = 	main.c\

OBJS = ${SRCS:.c=.o}

NAME = a.out

GCC = gcc

RM = rm -f

CFLAGS =  -Imlx

%.o: %.c
	$(GCC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
