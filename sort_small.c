/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:11:43 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 08:17:05 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Sorts a stack with two elements
void	sort_two_elements(t_stack **stack_a)
{
	int	a;
	int	b;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	a = (*stack_a)->number;
	b = (*stack_a)->next->number;
	if (a > b)
		ft_sa(stack_a, 0);
}

// Sorts a stack with three elements
void	sort_three_elemets(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->number;
	second = (*stack_a)->next->number;
	third = (*stack_a)->next->next->number;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		ft_sa(stack_a, 0);
	else if (first > second && second > third)
	{
		ft_ra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (first > second && second < third && first > third)
		ft_ra(stack_a, 0);
	else if (first < second && second > third && first < third)
	{
		ft_sa(stack_a, 0);
		ft_ra(stack_a, 0);
	}
	else if (first < second && second > third && first > third)
		ft_rra(stack_a, 0);
}

// Sorts four elements by moving the smallest to stack_b
void	sort_four_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	smallest = find_smallest(*stack_a);
	while ((*stack_a)->number != smallest)
		ft_ra(stack_a, 0);
	ft_pb(stack_a, stack_b, 0);
	sort_three_elemets(stack_a);
	ft_pa(stack_a, stack_b, 0);
}

// Moves the smallest 'count' elements from stack_a to stack_b
static void	move_smallest_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	smallest;
	int	position;
	int	stack_size;
	int	i;

	stack_size = get_stack_size(*stack_a);
	i = 0;
	while (i < count)
	{
		smallest = find_smallest(*stack_a);
		position = get_position(*stack_a, smallest);
		if (position <= stack_size / 2)
		{
			while ((*stack_a)->number != smallest)
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->number != smallest)
				ft_rra(stack_a, 0);
		}
		ft_pb(stack_a, stack_b, 0);
		stack_size--;
		i++;
	}
}

// Sorts five elements by moving the smallest two to stack_b
void	sort_five_elements(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_b == NULL || *stack_a == NULL)
		return ;
	move_smallest_to_b(stack_a, stack_b, 2);
	sort_three_elemets(stack_a);
	while (get_stack_size(*stack_b) > 0)
	{
		ft_pa(stack_a, stack_b, 0);
	}
}
