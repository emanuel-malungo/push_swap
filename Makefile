CC = cc
SRC_DIR = src
NAME = push_swap
LIBFT_DIR = libft
INCLUDE_DIR = include
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = $(SRC_DIR)/push_swap.c \
            $(SRC_DIR)/stack_operations/stack_utils.c \
            $(SRC_DIR)/stack_operations/push.c \
            $(SRC_DIR)/stack_operations/reverse_rotate.c \
            $(SRC_DIR)/stack_operations/rotate.c \
            $(SRC_DIR)/stack_operations/swap.c \
            $(SRC_DIR)/utilities/utils.c \
            $(SRC_DIR)/error_handling/input_validation.c \
            $(SRC_DIR)/error_handling/error_checking.c \
            $(SRC_DIR)/sorting_algorithms/sort_small.c \
            $(SRC_DIR)/sorting_algorithms/sort_utils.c \
            $(SRC_DIR)/sorting_algorithms/function_sorted.c \
            $(SRC_DIR)/sorting_algorithms/sort_big.c

OBJ_FILES = $(SRC_FILES:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I $(INCLUDE_DIR) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re