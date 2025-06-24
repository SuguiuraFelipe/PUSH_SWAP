/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:34:34 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/24 17:58:14 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	stack_size(t_stack *stack)
{
    int		size = 0;
    t_node	*tmp = stack->top;

    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

static void	normalize_stack(t_stack *a)
{
    t_node	*tmp;
    t_node	*cmp_node;

    tmp = a->top;
    while (tmp)
    {
        tmp->rank = 0;
        cmp_node = a->top;
        while (cmp_node)
        {
            tmp->rank += (cmp_node->value < tmp->value);
            cmp_node = cmp_node->next;
        }
        tmp = tmp->next;
    }
}

static int	find_max_bits(t_stack *stack)
{
    int		max = 0;
    int		bits = 0;
    t_node	*tmp = stack->top;

    while (tmp)
    {
        if (tmp->rank > max)
            max = tmp->rank;
        tmp = tmp->next;
    }
    while (max >> bits)
        bits++;
    return (bits);
}

static void	process_stacks(t_stack *a, t_stack *b, int bit)
{
    int	a_size = stack_size(a);
    int	b_size;
    int	i;

    for (i = 0; i < a_size; i++)
    {
        if ((a->top->rank >> bit) & 1)
            ra(a);
        else
            pb(a, b);
    }
    b_size = stack_size(b);
    for (i = 0; i < b_size; i++)
    {
        if ((b->top->rank >> bit) & 1)
            pa(a, b);
        else
            rb(b);
    }
}

void	radix(t_stack *a, t_stack *b)
{
    int	max_bits;
    int	bit;

    normalize_stack(a);
    max_bits = find_max_bits(a);
    bit = 0;
    while (bit < max_bits)
        process_stacks(a, b, bit++);
    while (b->top)
        pa(a, b);
}