/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:13:48 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/08 07:13:49 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rra(t_stack **stack_a, int j)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second_last = *stack_a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (j == 0)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stack_b, int j)
{
	t_stack	*second_last;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	second_last = *stack_b;
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (j == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int j)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (j == 0)
		ft_putstr_fd("rrr\n", 1);
}