/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:12:48 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 08:16:25 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Frees memory allocated for an array of strings
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

// Frees memory for a stack
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

// Frees memory for a sorted list
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
