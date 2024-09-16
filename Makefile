NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR)

SRCDIR = .
LIBFTDIR = libft

SRCS = $(SRCDIR)/push_swap.c \
       $(SRCDIR)/frees_memory.c \
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

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFTDIR) -lft
	@echo "Compilation completed!"

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado $<"

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "Object files removed!"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re
