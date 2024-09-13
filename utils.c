/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:12:48 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/12 13:18:22 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (current == NULL)
	{
		printf("A pilha está vazia.\n");
		return ;
	}
	while (current != NULL)
	{
		printf("%d\n", current->number);
		current = current->next;
	}
}

// Função auxiliar para liberar a memória da lista ordenada
void	free_sorted_list(t_stack **sorted_list)
{
	t_stack	*temp;

	while (*sorted_list)
	{
		temp = *sorted_list;
		*sorted_list = (*sorted_list)->next;
		free(temp);
	}
}
