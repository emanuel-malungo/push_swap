/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:14:02 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 08:15:49 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Creates a new stack node with the given number
t_stack	*ft_stack_new(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

// Adds a new node to the end of the stack
void	ft_stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
}

// Converts numbers to stack nodes and adds them to stack_a
static int	add_numbers_to_stack(t_stack **stack_a, char **numbers)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	while (numbers[i])
	{
		new_node = ft_stack_new(ft_atoi(numbers[i]));
		if (!new_node)
		{
			ft_free_stack(stack_a);
			return (0);
		}
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	return (1);
}

// Initializes stack_a from command-line arguments
t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**numbers;

	stack_a = NULL;
	numbers = ft_parse_arguments(argc, argv);
	if (!numbers)
		return (NULL);
	if (!add_numbers_to_stack(&stack_a, numbers))
	{
		if (argc > 1)
			ft_free_split(numbers);
		return (NULL);
	}
	if (argc > 1)
		ft_free_split(numbers);
	return (stack_a);
}
