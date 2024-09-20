/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operetion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:11:44 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 08:44:12 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Swaps the first two elements of stack_a
void	ft_sa(t_stack **stack_a, int j)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (j == 0)
		ft_putstr_fd("sa\n", 1);
}

// Rotates stack_a (top element moves to the bottom)
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

// Rotates stack_a in reverse (bottom element becomes the top)
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
