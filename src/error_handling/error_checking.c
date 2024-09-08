#include "../../include/push_swap.h"

int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0' || !ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_fill_numbers(char **numbers, char **argv, int argc)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
		{
			while (j > 0)
				free(numbers[--j]);
			free(numbers);
			return (-1);
		}
		k = 0;
		while (temp[k])
			numbers[j++] = temp[k++];
		free(temp);
		i++;
	}
	numbers[j] = NULL;
	return (0);
}

char	**ft_parse_arguments(int argc, char **argv)
{
	char	**numbers;

	if (argc <= 1)
		return (NULL);
	numbers = (char **)malloc((argc * 10) * sizeof(char *));
	if (!numbers)
		return (NULL);
	if (ft_fill_numbers(numbers, argv, argc) == -1)
		return (NULL);
	return (numbers);
}

int	is_within_int_limits(const char *str)
{
	long long int	result;
	int				sig;

	sig = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (sig == 1 && result > INT_MAX)
			return (0);
		if (sig == -1 && result < INT_MIN)
			return (0);
		str++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}

int	check_stack_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*cmp;

	current = stack;
	while (current != NULL)
	{
		cmp = current->next;
		while (cmp != NULL)
		{
			if (current->number == cmp->number)
				return (1);
			cmp = cmp->next;
		}
		current = current->next;
	}
	return (0);
}