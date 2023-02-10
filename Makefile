# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:34:23 by houmanso          #+#    #+#              #
#    Updated: 2023/02/06 23:00:39 by houmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
FRAM = -framework OpenGl -framework AppKit
SRC = fractol.c fractol_utils.c mandelbrot.c julia.c
NAME = fractol

all: ${NAME}

${NAME} : libft ${SRC} fractol.h
	cc ${CFLAGS} ./libft/libft.a ${SRC} -lmlx ${FRAM} -o ${NAME} -g

libft :
	make -C ./libft

clean :
	make -C ./libft clean
	rm -f ${OBJ}
	
fclean : clean
	make -C ./libft fclean
	rm -f ${NAME}
	
re : fclean all

.PHONY : all clean fclean re bonus libft