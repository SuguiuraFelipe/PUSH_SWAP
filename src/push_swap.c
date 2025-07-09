/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:24:36 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/07/09 16:15:17 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	free_and_quit(t_stack *stack)
{
	free_stack(stack);
	free(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	check_duplicates(t_stack *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = stack->top;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sort_stack(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		return ;
	b->top = NULL;
	if (stack_size(a) == 2)
		sa(a);
	else if (stack_size(a) < 6)
		sort_small(a, b);
	else
		radix(a, b);
	free_stack(b);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	b = malloc(sizeof(t_stack));
	a = malloc(sizeof(t_stack));
	if (!a || !b)
		return (1);
	a->top = NULL;
	b->top = NULL;
	if (!init_stack(++argv, a))
		free_and_quit(a);
	if (!check_duplicates(a))
		free_and_quit(a);
	if (!is_sorted(a))
		sort_stack(a);
	free_stack(a);
	free(a);
	free_stack(b);
	free(b);
	return (0);
}
