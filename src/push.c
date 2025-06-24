/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:35:30 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/24 18:37:50 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node *node;

    if (!stack_a || !stack_b || is_empty(stack_b))
        return;
    node = stack_b->top;
    stack_b->top = node->next;
    node->next = stack_a->top;
    stack_a->top = node;
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node *node;

    if (!stack_a || !stack_b || is_empty(stack_a))
        return;
    node = stack_a->top;
    stack_a->top = node->next;
    node->next = stack_b->top;
    stack_b->top = node;
    write(1, "pb\n", 3);
}
