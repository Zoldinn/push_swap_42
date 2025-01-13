NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I ft_printf -I libft -g

OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

SRC = moves.c \
	push_swap.c \
	list_init.c \
	algo_utils.c \
	algo.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	cc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

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