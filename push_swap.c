/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:14:43 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/16 08:16:47 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!validate_arguments(argc, argv))
	{
		if (argc < 2)
			return (0);
		ft_error();
	}
	stack_a = init_stack(argc, argv);
	if (check_stack_duplicates(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_error();
	}
	if (!stack_is_sorted(stack_a))
	{
		ft_sorted(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (0);
}
