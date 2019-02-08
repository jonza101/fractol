# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:51:37 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/02/08 17:54:26 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c mandelbrot.c julia.c burning_ship.c spider.c thorn.c biomorph.c mouse.c draw_figs.c fractal_check.c color.c add_funcs.c threads.c

LIBFT = libft/
LIB_OBJ = libft/*.o
LIB_FILES = libft/*.c

INCLUDE = fractol.h

FLAGS = -Wall -Wextra -Werror -std=c99 -lpthread

FLAGS += -Ofast

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE) $(LIB_FILES) $(LIB_OBJ)
	@make -C libft/
	gcc $(FLAGS) $(SRC) -L $(LIBFT) -lft  -I $(INCLUDE) -lmlx -framework OpenGL -framework AppKit -framework OpenCL -o $(NAME)

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
	@make re -C libft/