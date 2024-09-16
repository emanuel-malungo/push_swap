/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:12:19 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 08:19:06 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Returns the number of elements in the stack
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// Finds the largest number in the stack
int	find_largest(t_stack *stack)
{
	int	largest;

	if (stack == NULL)
		return (0);
	largest = stack->number;
	while (stack != NULL)
	{
		if (stack->number > largest)
			largest = stack->number;
		stack = stack->next;
	}
	return (largest);
}

// Finds the smallest number in the stack
int	find_smallest(t_stack	*stack)
{
	int	smallest;

	if (stack == NULL)
		return (0);
	smallest = stack->number;
	while (stack != NULL)
	{
		if (stack->number < smallest)
			smallest = stack->number;
		stack = stack->next;
	}
	return (smallest);
}

// Checks if the stack is sorted in ascending order
int	stack_is_sorted(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Returns the position of a number in the stack
int	get_position(t_stack *stack, int number)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->number == number)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}
