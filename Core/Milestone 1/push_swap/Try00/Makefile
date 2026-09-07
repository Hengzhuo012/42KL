# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namak <namak@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/07 08:53:13 by namak             #+#    #+#              #
#    Updated: 2026/09/07 15:53:52 by namak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC = push_swap.c print_output.c check_inputs.c initialise.c \
	op_push.c op_rotate.c op_rrotate.c op_swap.c \
	simple_sort.c medium_sort.c complex_sort.c \
	sort_utils.c push_swap_utils.c

SRC_BONUS = checker_bonus.c check_inputs_bonus.c op_push_bonus.c \
		op_rotate_bonus.c op_rrotate_bonus.c op_swap_bonus.c push_swap_utils.c \
		print_output.c checker_bonus_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

#rename libft.a into push_swap.a
#then add *.c for push_swap into push_swap.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

bonus: $(NAME_BONUS)
$(NAME_BONUS):$(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

re: fclean all


.PHONY: all clean fclean re bonus
