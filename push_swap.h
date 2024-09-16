/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:07:51 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 12:16:26 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct t_stack{
	int				number;
	struct t_stack	*next;
}				t_stack;

// error_checking.c
int		is_valid_number(const char *str);
int		is_within_int_limits(const char *str);
int		check_stack_duplicates(t_stack *stack);
char	**ft_parse_arguments(int argc, char **argv);

// input_validation.c
void	ft_error(void);
int		validate_arguments(int argc, char **argv);

// utils.c
void	ft_free_split(char **split);
void	ft_free_stack(t_stack **stack);
void	free_sorted_list(t_stack **sorted_list);

// stack_utils.c
t_stack	*ft_stack_new(int number);
t_stack	*init_stack(int argc, char **argv);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);

// stack_operetion.c
void	ft_sa(t_stack **stack_a, int j);
void	ft_ra(t_stack **stack_a, int j);
void	ft_rra(t_stack **stack_a, int j);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j);

// sort_small.c
void	sort_two_elements(t_stack **stack_a);
void	sort_three_elemets(t_stack **stack_a);
void	sort_four_elements(t_stack **stack_a, t_stack **stack_b);
void	sort_five_elements(t_stack **stack_a, t_stack **stack_b);

// sort_utils.c
int		find_largest(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		find_smallest(t_stack	*stack);
int		stack_is_sorted(t_stack *stack);
int		get_position(t_stack *stack, int number);

// function_sorted.c
void	ft_sorted(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	ft_sorted_big(t_stack **stack_a, t_stack **stack_b);

// radix_sort.c
int		get_max_bits(t_stack *stack);
void	collect(t_stack **stack_a, t_stack **stack_b);
void	ft_stack_add_sorted(t_stack **sorted_list, t_stack *new_node);

// radix_sort.c
void	map_numbers(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	distribute(t_stack **stack_a, t_stack **stack_b, int bit);

#endif
