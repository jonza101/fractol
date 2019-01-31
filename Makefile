# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:51:37 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/01/31 14:58:12 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c mandelbrot.c julia.c kernel.c test.c

all: $(NAME)

$(NAME):
	gcc -g $(SRC) -Ifractol.h libft/libft.a -lmlx -framework OpenGL -framework AppKit -framework OpenCL

clean:
	rm -rf $(NAME)