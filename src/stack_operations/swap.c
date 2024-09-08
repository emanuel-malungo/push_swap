#include "../../include/push_swap.h"

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

void	ft_sb(t_stack **stack_b, int j)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (j == 0)
		ft_putstr_fd("sb", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int j)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (j == 0)
		ft_putstr_fd("ss\n", 1);
}