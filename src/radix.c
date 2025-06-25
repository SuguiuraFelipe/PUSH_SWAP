/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:34:34 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/25 16:29:58 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	int		max;
	int		bits;
	t_node	*tmp;

	max = 0;
	bits = 0;
	tmp = stack->top;
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
	int	a_size;
	int	b_size;
	int	i;

	i = 0;
	a_size = stack_size(a);
	while (i < a_size)
	{
		if ((a->top->rank >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	i = 0;
	b_size = stack_size(b);
	while (i < b_size)
	{
		if ((b->top->rank >> bit) & 1)
			pa(a, b);
		else
			rb(b);
		i++;
	}
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = stack->top;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
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
