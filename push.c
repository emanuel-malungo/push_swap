/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:13:40 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 08:15:21 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Pushes the top element of stack_b onto stack_a
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (j == 0)
		ft_putstr_fd("pa\n", 1);
}

// Pushes the top element of stack_a onto stack_b
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (j == 0)
		ft_putstr_fd("pb\n", 1);
}
