CC = cc
SRCDIR = .
LIBFTDIR = libft
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR)

SRCS = $(SRCDIR)/push_swap.c \
       $(SRCDIR)/frees_memory.c \
       $(SRCDIR)/error_checking.c \
       $(SRCDIR)/input_validation.c \
       $(SRCDIR)/radix_sort.c \
       $(SRCDIR)/radix_utils.c \
       $(SRCDIR)/sort_utils.c \
       $(SRCDIR)/function_sorted.c \
       $(SRCDIR)/sort_small.c \
       $(SRCDIR)/stack_utils.c \
       $(SRCDIR)/stack_operetion.c \

OBJS = $(SRCDIR)/push_swap.o \
       $(SRCDIR)/frees_memory.o \
       $(SRCDIR)/error_checking.o \
       $(SRCDIR)/input_validation.o \
       $(SRCDIR)/radix_sort.o \
       $(SRCDIR)/radix_utils.o \
       $(SRCDIR)/sort_utils.o \
       $(SRCDIR)/function_sorted.o \
       $(SRCDIR)/sort_small.o \
       $(SRCDIR)/stack_utils.o \
       $(SRCDIR)/stack_operetion.o \

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft
	@echo "Compilation completed!"

$(SRCDIR)/push_swap.o: $(SRCDIR)/push_swap.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/push_swap.c -o $(SRCDIR)/push_swap.o
	@echo "Compiled $(SRCDIR)/push_swap.c"

$(SRCDIR)/frees_memory.o: $(SRCDIR)/frees_memory.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/frees_memory.c -o $(SRCDIR)/frees_memory.o
	@echo "Compiled $(SRCDIR)/frees_memory.c"

$(SRCDIR)/error_checking.o: $(SRCDIR)/error_checking.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/error_checking.c -o $(SRCDIR)/error_checking.o
	@echo "Compiled $(SRCDIR)/error_checking.c"

$(SRCDIR)/input_validation.o: $(SRCDIR)/input_validation.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/input_validation.c -o $(SRCDIR)/input_validation.o
	@echo "Compiled $(SRCDIR)/input_validation.c"

$(SRCDIR)/radix_sort.o: $(SRCDIR)/radix_sort.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/radix_sort.c -o $(SRCDIR)/radix_sort.o
	@echo "Compiled $(SRCDIR)/radix_sort.c"

$(SRCDIR)/radix_utils.o: $(SRCDIR)/radix_utils.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/radix_utils.c -o $(SRCDIR)/radix_utils.o
	@echo "Compiled $(SRCDIR)/radix_utils.c"

$(SRCDIR)/sort_utils.o: $(SRCDIR)/sort_utils.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/sort_utils.c -o $(SRCDIR)/sort_utils.o
	@echo "Compiled $(SRCDIR)/sort_utils.c"

$(SRCDIR)/function_sorted.o: $(SRCDIR)/function_sorted.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/function_sorted.c -o $(SRCDIR)/function_sorted.o
	@echo "Compiled $(SRCDIR)/function_sorted.c"

$(SRCDIR)/sort_small.o: $(SRCDIR)/sort_small.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/sort_small.c -o $(SRCDIR)/sort_small.o
	@echo "Compiled $(SRCDIR)/sort_small.c"

$(SRCDIR)/stack_utils.o: $(SRCDIR)/stack_utils.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/stack_utils.c -o $(SRCDIR)/stack_utils.o
	@echo "Compiled $(SRCDIR)/stack_utils.c"

$(SRCDIR)/stack_operetion.o: $(SRCDIR)/stack_operetion.c
	@$(CC) $(CFLAGS) -c $(SRCDIR)/stack_operetion.c -o $(SRCDIR)/stack_operetion.o
	@echo "Compiled $(SRCDIR)/stack_operetion.c"

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
