# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:51:37 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/02/03 19:38:11 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c mandelbrot.c julia.c mouse.c burning_ship.c spider.c get_next_line/get_next_line.c get_next_line/libft/libft.a kernel.c

all: $(NAME)

$(NAME):
	gcc -g $(SRC) -Ifractol.h -lmlx -framework OpenGL -framework AppKit -framework OpenCL

clean:
	rm -rf $(NAME)