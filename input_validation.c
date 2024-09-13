/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 07:10:54 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/11 15:24:58 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	validate_arguments(int argc, char **argv)
{
	int		i;
	char	**numbers;

	numbers = ft_parse_arguments(argc, argv);
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]) || !is_within_int_limits(numbers[i]))
			return (0);
		i++;
	}
	if (argc > 1)
		ft_free_split(numbers);
	return (1);
}
