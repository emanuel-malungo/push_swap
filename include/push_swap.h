#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limist.h>
# include "../libf/libft.h"

typedef struct t_stack{
	int				number;
	struct t_stack	*next;
}				t_stack;

// error_handling/error_checking.c
int	    is_valid_number(const char *str);
int	    is_within_int_limits(const char *str);
int	    check_stack_duplicates(t_stack *stack);
char	**ft_parse_arguments(int argc, char **argv);

// error_handling/input_validation.c
void	ft_error(void);
int	    validate_arguments(int argc, char **argv);

// utilities/utils.c
void	ft_free_split(char **split);
void	ft_free_stack(t_stack **stack);

// stack_operations/stack_utils.c
t_stack	*ft_stack_new(int number);
t_stack	*init_stack(int argc, char **argv)
void	ft_stack_add_back(t_stack **stack, t_stack *new_node)

// stack_operations/push.c
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j);

// stack_operations/swap.c
void	ft_sa(t_stack **stack_a, int j);
void	ft_sb(t_stack **stack_b, int j);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int j);

// stack_operations/rotate.c
void	ft_ra(t_stack **stack_a, int j);
void	ft_rb(t_stack **stack_b, int j);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int j);

// stack_operations/reverse_rotate.c
void	ft_rra(t_stack **stack_a, int j)
void	ft_rrb(t_stack **stack_b, int j);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int j);

// sorting_algorithms/sort_small.c
void	sort_two_elements(t_stack **stack_a);
void	sort_three_elemets(t_stack **stack_a);
void	sort_four_elements(t_stack **stack_a, t_stack **stack_b);
void	sort_five_elements(t_stack **stack_a, t_stack **stack_b);

// sorting_algorithms/sort_utils.c
int     find_largest(t_stack *stack);
int     get_stack_size(t_stack *stack);
int	    find_smallest(t_stack	*stack);
int	    stack_is_sorted(t_stack *stack);
int	    get_position(t_stack *stack, int number);
#endif