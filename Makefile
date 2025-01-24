NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I ft_printf -I libft -g

OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

SRC = moves.c \
	push_swap.c \
	list_init.c \
	algo.c \
	algo_utils.c \
	algo_utils2.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "🔨 Compilation de $(NAME)..."
	@cc $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "✅ Compilation réussie !"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "🔧 Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "📦 Compilation de la libft..."
	@make -s -C $(LIBFT_DIR) bonus

$(PRINTF):
	@echo "📦 Compilation de ft_printf..."
	@make -s -C $(PRINTF_DIR)

clean:
	@echo "🧹 Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(PRINTF_DIR) clean
	@echo "✅ Nettoyage terminé !"

fclean: clean
	@echo "🗑️ Suppression de $(NAME)..."
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(PRINTF_DIR) fclean
	@echo "✅ Tout a été supprimé !"

re: fclean all

.PHONY: all clean fclean re
