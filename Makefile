# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/09 18:04:07 by ggerhold          #+#    #+#              #
#    Updated: 2019/07/22 12:31:47 by ggerhold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap
CC = gcc
FLAGS = -g -Wall -Werror -Wextra

LIBFT_DIR = ./libft
SRC_DIR_CHECKER = ./src-checker
SRC_DIR_PUSH_SWAP = ./src-push_swap
INC_DIR = ./inc
OBJ_DIR_CHECKER = ./obj-checker
OBJ_DIR_PUSH_SWAP = ./obj-push_swap

SRC_CHECKER		=   free.c \
                    instructions.c \
                    lsts.c \
                    main.c \
                    reader.c \
                    tools.c \
                    validation.c

SRC_PUSH_SWAP	=   a_sort_commands.c \
                    a_sort_vip.c \
                    a_sort.c \
                    b_sort_commands.c \
                    b_sort_vip.c \
                    b_sort.c \
                    free.c \
                    instructions.c \
                    lsts.c \
                    main.c \
                    median.c \
                    merge.c \
                    partition.c \
                    push_swap.c \
                    reverse.c \
                    sequence.c \
                    tools.c \
                    validation.c

OBJS_CHECKER = $(addprefix $(OBJ_DIR_CHECKER)/,$(SRC_CHECKER:%.c=%.o))
OBJS_PUSH_SWAP = $(addprefix $(OBJ_DIR_PUSH_SWAP)/,$(SRC_PUSH_SWAP:%.c=%.o))
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/inc

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(OBJ_DIR_CHECKER):
	@mkdir -p $(OBJ_DIR_CHECKER)

$(OBJ_DIR_PUSH_SWAP):
	@mkdir -p $(OBJ_DIR_PUSH_SWAP)

$(LIBFT):
	@make -C libft

$(NAME_CHECKER): $(OBJ_DIR_CHECKER) $(LIBFT) $(OBJS_CHECKER)
	@$(CC) $(FLAGS) -o $(NAME_CHECKER) $(OBJS_CHECKER) -L $(LIBFT_DIR) -lft

$(NAME_PUSH_SWAP): $(OBJ_DIR_PUSH_SWAP) $(LIBFT) $(OBJS_PUSH_SWAP)
	@$(CC) $(FLAGS) -o $(NAME_PUSH_SWAP) $(OBJS_PUSH_SWAP) -L $(LIBFT_DIR) -lft

$(OBJ_DIR_CHECKER)/%.o: $(SRC_DIR_CHECKER)/%.c
	@$(CC) $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

$(OBJ_DIR_PUSH_SWAP)/%.o: $(SRC_DIR_PUSH_SWAP)/%.c
	@$(CC) $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

clean:
	@rm -rf $(OBJ_DIR_CHECKER)
	@rm -rf $(OBJ_DIR_PUSH_SWAP)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME_CHECKER)
	@rm -rf $(NAME_PUSH_SWAP)
	@make -C libft fclean

re: fclean all

norm:
	@make -C libft norm
	@norminette $(SRC_DIR_CHECKER) $(SRC_DIR_PUSH_SWAP) $(INC_DIR)

.PHONY: all clean fclean re norm
