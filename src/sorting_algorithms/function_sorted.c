/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:25:58 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/08 07:30:43 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elemets(stack_a);
	else if (size == 4)
		sort_four_elements(stack_a, stack_b);
	else if (size == 5)
		sort_five_elements(stack_a, stack_b);
}

void	ft_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size > 1 && size < 6)
		sort_small(stack_a, stack_b);
	/*
	if (size > 5)
	{
		selection_sort(stack_a, stack_b);
	}
	*/
}