NAME = push_swap.a
SRC = ft_printf.c print_conversions.c print_conversions_2.c print_conversions_3.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_printf_bonus.c check_bonus.c initialise_bonus.c \
	print_helper_numbers_bonus.c print_helper_flags_bonus.c \
	print_char_bonus.c print_decimal_bonus.c print_hexa_number_bonus.c \
	print_hexa_pointer_bonus.c print_string_bonus.c print_unsigned_decimal_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

#rename libft.a into push_swap.a
#then add *.c for push_swap into push_swap.a

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
