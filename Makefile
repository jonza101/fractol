# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 13:51:37 by zjeyne-l          #+#    #+#              #
#    Updated: 2019/02/08 18:22:01 by zjeyne-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# PATHS TO C SOURCE FILES
SRC_PATH = $(wildcard $(SRC_DIR)/*.c)

# PATHS TO OBJECTS
OBJ_PATH = $(SRC_PATH:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# PATH TO LIBFT
LIB_NAME = libft.a
LIB_PATH = libft
LIB = -lft

# MLX INFO
MLX = -lpthread -lmlx -framework OpenGL -framework AppKit

# COMPILATION RULES
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c99 -Ofast
NAME = fractol

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_PATH) $(LIB_PATH)/$(LIB_NAME)
	$(CC) $(FLAGS) $(OBJ_PATH) -o $@ -I$(INC_DIR) -I$(LIB_PATH)/$(INC_DIR) -L$(LIB_PATH) $(LIB) $(MLX) 

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(INC_DIR) -I$(LIB_PATH)/$(INC_DIR)

$(LIB_PATH)/$(LIB_NAME):
	make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all