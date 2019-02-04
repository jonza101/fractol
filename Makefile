# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:51:37 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/02/04 18:48:14 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c mandelbrot.c julia.c burning_ship.c spider.c newton.c thorn.c triangle.c mouse.c draw_figs.c get_next_line/get_next_line.c get_next_line/libft/libft.a kernel.c

FLAGS = -std=c99

all: $(NAME)

$(NAME):
	gcc -g $(FLAGS) $(SRC) -Ifractol.h -lmlx -framework OpenGL -framework AppKit -framework OpenCL

clean:
	rm -rf $(NAME)