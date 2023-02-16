# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:34:23 by houmanso          #+#    #+#              #
#    Updated: 2023/02/13 15:55:21 by houmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
FRAM = -framework OpenGl -framework AppKit
SRC = fractol.c fractol_utils.c mandelbrot.c julia.c
B_SRC = fractol_bonus.c \
	fractol_utils_bonus.c \
	mandelbrot_bonus.c \
	julia_bonus.c \
	julia_utils_bonus.c \
	mandel3_bonus.c
NAME = fractol
B_NAME = fractol_bonus

all: ${NAME}

${NAME} : libft ${SRC} fractol.h
	cc ${CFLAGS} ./libft/libft.a ${SRC} -lmlx ${FRAM} -o ${NAME}

libft :
	make -C ./libft

clean :
	make -C ./libft clean
	rm -f ${OBJ}
	
fclean : clean
	make -C ./libft fclean
	rm -f ${NAME}

bonus: libft ${B_SRC} fractol_bonus.h
	cc ${CFLAGS} ./libft/libft.a ${B_SRC} -lmlx ${FRAM} -o ${B_NAME}
re : fclean all

.PHONY : all clean fclean re bonus libft