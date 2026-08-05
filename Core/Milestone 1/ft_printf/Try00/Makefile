NAME = libftprintf.a
SRC = ft_printf.c check.c initialise.c print_helper_numbers.c \
	print_helper_flags.c \
	print_char.c print_decimal.c print_hexa_number.c print_hexa_pointer.c \
	print_string.c print_unsigned_decimal.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

#rename libft.a into libftprintf.a
#then add *.c for ft_print into libftprint.a

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
