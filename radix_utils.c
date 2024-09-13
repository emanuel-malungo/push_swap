/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:50:59 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/13 12:52:23 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	compare(const void *a, const void *b)
{
	return ((*(int *)a) - (*(int *)b));
}

// Coleta os números de volta à pilha A
void	collect(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_pa(stack_a, stack_b, 0);
}

// Obtém o número máximo de bits necessário
int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	bits;

	bits = 0;
	max_num = find_largest(stack);
	while (max_num > 0)
	{
		bits++;
		max_num >>= 1;
	}
	return (bits);
}

// Adiciona um nó na lista ordenada
void	ft_stack_add_sorted(t_stack **sorted_list, t_stack *new_node)
{
	t_stack	*current;

	if (!*sorted_list || (*sorted_list)->number >= new_node->number)
	{
		new_node->next = *sorted_list;
		*sorted_list = new_node;
	}
	else
	{
		current = *sorted_list;
		while (current->next && current->next->number < new_node->number)
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}
