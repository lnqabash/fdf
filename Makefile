# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 15:11:33 by lnqabash          #+#    #+#              #
#    Updated: 2018/08/25 09:26:34 by lnqabash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

cc = gcc
C_FLAGS = -Wall -Wextra -Werror -g
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g
# FRAM = -framework OpenGL -framework AppKit minilibx/libmlx.a

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fdf.h
SRC_NAME = main.c key_func.c read.c draw.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft $^ -o $@
				
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<
		@echo -n =

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		
re: fclean all
