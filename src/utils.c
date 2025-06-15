/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:08:18 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/15 14:20:38 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

t_node *create_node(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push(t_stack *stack, int value)
{
    t_node *new_node = create_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(t_stack *stack)
{
    if (is_empty(stack))
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    return (value);
}

int is_empty(t_stack *stack)
{
    return (stack->top == NULL);
}

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
}

void error_and_exit(t_stack *stack_a, t_stack *stack_b)
{
    fprintf(stderr, "Error\n");
    if (stack_a)
        free_stack(stack_a);
    if (stack_b)
        free_stack(stack_b);
    exit(EXIT_FAILURE);
}
