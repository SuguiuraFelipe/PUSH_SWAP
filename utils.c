/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:08:18 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/13 21:32:00 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_node *create_node(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push(t_stack *stack, int value)
{
    t_node *new_node = create_node(value);
    if (!new_node)
        return ;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(t_stack *stack)
{
    if (!stack->top)
        return (0);
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free (temp);
    return (value);
}

int is_empty(t_stack *stack)
{
    return (stack->top == NULL);
}
