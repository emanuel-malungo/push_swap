/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:22:16 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/17 13:43:20 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper function to create the ordered helper list
void	create_sorted_list(t_stack *stack, t_stack **sorted_list)
{
	t_stack	*temp;
	t_stack	*current;

	current = stack;
	while (current)
	{
		temp = ft_stack_new(current->number);
		if (!temp)
			return ;
		ft_stack_add_sorted(sorted_list, temp);
		current = current->next;
	}
}

// Auxiliary function to update the original stack with indexes
void	update_stack_with_indices(t_stack *stack, t_stack *sorted_list)
{
	t_stack	*temp;
	int		index;

	while (stack)
	{
		temp = sorted_list;
		index = 0;
		while (temp)
		{
			if (temp->number == stack->number)
			{
				stack->number = index;
				break ;
			}
			temp = temp->next;
			index++;
		}
		stack = stack->next;
	}
}

// Function to sort and map the stack numbers
void	map_numbers(t_stack **stack)
{
	t_stack	*sorted_list;

	sorted_list = NULL;
	if (!*stack || !(*stack)->next)
		return ;
	create_sorted_list(*stack, &sorted_list);
	update_stack_with_indices(*stack, sorted_list);
	free_sorted_list(&sorted_list);
}

// Distributes the numbers based on the current bit
void	distribute(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	bit_mask;
	int	size;
	int	i;

	i = 0;
	bit_mask = 1 << bit;
	size = get_stack_size(*stack_a);
	while (i < size)
	{
		if (((*stack_a)->number & bit_mask) == 0)
			ft_pb(stack_a, stack_b, 0);
		else
			ft_ra(stack_a, 0);
		i++;
	}
}

// Main function for sorting using radix sort
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	i;

	i = 0;
	map_numbers(stack_a);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		distribute(stack_a, stack_b, i);
		collect(stack_a, stack_b);
		i++;
	}
}
