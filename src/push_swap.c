/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:24:36 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/15 14:21:48 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

int has_duplicate(t_stack *stack, int value)
{
    t_node *current = stack->top;
    while (current)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

void validate_and_parse_args(int ac, char **av, t_stack *stack_a)
{
    int         i;
    long int    nb;
    char        *endptr;

    if (ac < 2)
        return;

    i = ac - 1;
    while (i >= 1)
    {
        errno = 0; 
        nb = strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || endptr == av[i] || (errno == ERANGE && (nb == LONG_MAX || nb == LONG_MIN)) || nb < INT_MIN || nb > INT_MAX)
            error_and_exit(stack_a, NULL);
        if (has_duplicate(stack_a, (int)nb))
            error_and_exit(stack_a, NULL);
        push(stack_a, (int)nb);
        i--;
    }
}

int main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;

    stack_a.top = NULL;
    stack_b.top = NULL;

    validate_and_parse_args(ac, av, &stack_a);

    // Fase 2: Implementar o algoritmo de ordenação aqui

    free_stack(&stack_a);
    free_stack(&stack_b);

    return (0);
}
