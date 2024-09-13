# Nome do executável
NAME = push_swap

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR)

# Diretórios
SRCDIR = .
LIBFTDIR = libft

# Arquivos fonte e objetos
SRCS = $(SRCDIR)/push_swap.c \
       $(SRCDIR)/utils.c \
       $(SRCDIR)/error_checking.c \
       $(SRCDIR)/input_validation.c \
       $(SRCDIR)/push.c \
       $(SRCDIR)/reverse_rotate.c \
       $(SRCDIR)/radix_sort.c \
       $(SRCDIR)/radix_utils.c \
       $(SRCDIR)/sort_utils.c \
       $(SRCDIR)/swap.c \
       $(SRCDIR)/function_sorted.c \
       $(SRCDIR)/sort_small.c \
       $(SRCDIR)/stack_utils.c \
       $(SRCDIR)/rotate.c \

OBJS = $(SRCS:.c=.o)

# Regras
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFTDIR) -lft
	@echo "Compilação concluída!"

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado $<"

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "Arquivos objeto removidos!"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "Executável removido!"

re: fclean all

.PHONY: all clean fclean re
