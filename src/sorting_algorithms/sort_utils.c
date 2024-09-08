#include "../../include/push_swap.h"

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