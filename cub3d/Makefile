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
		gnl.c\
		gnl_utils.c \
		ft_split.c \
		error_logs.c \
		reader.c \
		setting_inicializ.c \
		valid_args.c \

OBJS = ${SRCS:.c=.o}

NAME = a.out

GCC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Imlx

%.o: %.c
	$(GCC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}:	${OBJS}
			$(GCC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${OBJS} -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
