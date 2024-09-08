/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:10:54 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/08 07:11:00 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	validate_arguments(int argc, char **argv)
{
	int		i;
	int		is_valid;
	char	**numbers;

	numbers = ft_parse_arguments(argc, argv);
	if (!numbers)
		return (0);
	i = 0;
	is_valid = 1;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]) || !is_within_int_limits(numbers[i]))
		{
			is_valid = 0;
			break ;
		}
		i++;
	}
	if (argc > 1)
		ft_free_split(numbers);
	return (is_valid);
}