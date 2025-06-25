/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:08:18 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/25 16:30:32 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		str++;
	}
	return ((int)(result * sign));
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	init_stack(char **argv, t_stack *stack)
{
	int		nb;
	t_node	*new_node;
	t_node	*last_node;

	last_node = NULL;
	while (*argv)
	{
		nb = ft_atoi(*argv);
		new_node = create_node(nb);
		if (!new_node)
			return (0);
		if (!stack->top)
			stack->top = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		argv++;
	}
	return (1);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
