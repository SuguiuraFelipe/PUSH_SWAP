/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:21:57 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/25 16:24:22 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last_node;
	t_node	*penultimate_node;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last_node = stack->top;
	penultimate_node = NULL;
	while (last_node->next != NULL)
	{
		penultimate_node = last_node;
		last_node = last_node->next;
	}
	if (penultimate_node)
	{
		penultimate_node->next = NULL;
	}
	last_node->next = stack->top;
	stack->top = last_node;
	write(1, "rra\n", 4);
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
