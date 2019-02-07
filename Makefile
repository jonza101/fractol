# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:51:37 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/02/07 19:01:09 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c mandelbrot.c julia.c burning_ship.c spider.c thorn.c biomorph.c mouse.c draw_figs.c fractal_check.c color.c libft/libft.a

INCLUDE = -I fractol.h

FLAGS = -Wall -Wextra -Werror -std=c99 -lpthread

FLAGS += -Ofast

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	gcc $(FLAGS) $(SRC) $(INCLUDE) -lmlx -framework OpenGL -framework AppKit -framework OpenCL -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all