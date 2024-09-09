#include "../../include/push_swap.h"

int find_insertion_position(t_stack *stack, int number) {
    int position = 0;

    if (!stack || number <= stack->number) {
        return 0;
    }

    while (stack->next != NULL && stack->next->number < number) {
        stack = stack->next;
        position++;
    }

    if (stack->next == NULL || stack->next->number >= number) {
        return position + 1;
    }

    return position;
}


int calculate_rra_cost(int total_size, int position) {
    return total_size - position;
}
int calculate_ra_cost(int position) {
    return position;
}
void move_all_but_three(t_stack **stack_a, t_stack **stack_b) {
    while (get_stack_size(*stack_a) > 3) {
        int smallest = find_smallest(*stack_a);
        int position = get_position(*stack_a, smallest);
        int stack_size = get_stack_size(*stack_a);

        if (position <= stack_size / 2) {
            while ((*stack_a)->number != smallest)
                ft_ra(stack_a, 0);
        } else {
            while ((*stack_a)->number != smallest)
                ft_rra(stack_a, 0);
        }
        ft_pb(stack_a, stack_b, 0);
    }
}
void insert_elements_back(t_stack **stack_a, t_stack **stack_b) {
    while (get_stack_size(*stack_b) > 0) {
        t_stack *current = *stack_b;
        int value = current->number;
        int position = find_insertion_position(*stack_a, value);

        int stack_size = get_stack_size(*stack_a);
        int ra_cost = calculate_ra_cost(position);
        int rra_cost = calculate_rra_cost(stack_size, position);

        if (ra_cost <= rra_cost) {
            for (int i = 0; i < ra_cost; i++)
                ft_ra(stack_a, 0);
        } else {
            for (int i = 0; i < rra_cost; i++)
                ft_rra(stack_a, 0);
        }
        ft_pa(stack_a, stack_b, 0);
    }
}