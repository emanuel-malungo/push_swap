/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:25:58 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/12 13:59:56 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stakc_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elemets(stack_a);
	else if (size == 4)
		sort_four_elements(stack_a, stakc_b);
	else
		sort_five_elements(stack_a, stakc_b);
}

void	ft_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size >= 2 && size <= 5)
		sort_small(stack_a, stack_b);
	if (size > 5)
	{
		radix_sort(stack_a, stack_b);
	}
}
