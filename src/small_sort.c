/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:38:37 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/25 16:34:55 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a->top || !a->top->next || !a->top->next->next)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_min_index(t_stack *stack)
{
	int		i;
	int		min_i;
	int		min_value;
	t_node	*tmp;

	i = 0;
	min_i = 0;
	tmp = stack->top;
	min_value = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_i = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_i);
}

void	bring_min_to_top(t_stack *a, int min_i, int size)
{
	int	i;

	if (min_i <= size / 2)
	{
		i = min_i;
		while (i-- > 0)
			ra(a);
	}
	else
	{
		i = size - min_i;
		while (i-- > 0)
			rra(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min_i;
	int	size;

	size = stack_size(a);
	while (size > 3)
	{
		min_i = find_min_index(a);
		bring_min_to_top(a, min_i, size);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (b && b->top)
		pa(a, b);
}
