NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I ft_printf -I libft

OBJ_DIR = obj
SRC_DIR = src
LIBFTD_IR = libft
PRINTF_DIR = ft_printf

SRC = moves.c \
	push_swap.c \
	utils_lists.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/ft_printf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	cc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p %(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re