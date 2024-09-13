/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:13:54 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/12 14:00:13 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_ra(t_stack **stack_a, int j)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (j == 0)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stack_b, int j)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	if (j == 0)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int j)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (j == 0)
		ft_putstr_fd("rr\n", 1);
}
