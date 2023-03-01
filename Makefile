# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:34:23 by houmanso          #+#    #+#              #
#    Updated: 2023/03/01 23:30:01 by houmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
FRAM = -framework OpenGl -framework AppKit
SRC = fractol.c \
	fractol_utils.c \
	mandelbrot_utils.c \
	mandelbrot.c \
	julia_utils.c \
	julia.c
OBJ = ${SRC:.c=.o}
B_SRC = fractol_bonus.c \
	fractol_utils_bonus.c \
	mandelbrot_bonus.c \
	julia_bonus.c \
	mandel3_bonus.c \
	mandelbrot_utils_bonus.c \
	mandel3_utils_bonus.c \
	julia_utils_bonus.c
B_OBJ = ${B_SRC:.c=.o}
NAME = fractol
B_NAME = fractol_bonus

all: ${NAME}

${NAME} : libft ${OBJ}
	cc ${CFLAGS} ./libft/libft.a ${OBJ} -lmlx ${FRAM} -o ${NAME}

%.o : %.c 
	cc ${CFLAGS} -c $< -o $@

libft :
	make -C ./libft

clean :
	make -C ./libft clean
	rm -f ${OBJ}
	
fclean : clean
	make -C ./libft fclean
	rm -f ${NAME} ${B_NAME}

bonus: libft ${B_OBJ} fractol_bonus.h
	cc ${CFLAGS} ./libft/libft.a ${B_OBJ} -lmlx ${FRAM} -o ${B_NAME}
re : fclean all

.PHONY : all clean fclean re bonus libft