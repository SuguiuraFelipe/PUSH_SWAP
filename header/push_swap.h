/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:09:13 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/15 14:20:13 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

t_node *create_node(int value);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int is_empty(t_stack *stack);
void free_stack(t_stack *stack);

void error_and_exit(t_stack *stack_a, t_stack *stack_b);
void validate_and_parse_args(int ac, char **av, t_stack *stack_a);

// Protótipos das Operações de Push_Swap (se você já os tiver)
// Exemplo:
// void sa(t_stack *stack_a);
// void sb(t_stack *stack_b);
// void ss(t_stack *stack_a, t_stack *stack_b);
// void pa(t_stack *stack_a, t_stack *stack_b);
// void pb(t_stack *stack_a, t_stack *stack_b);
// void ra(t_stack *stack_a);
// void rb(t_stack *stack_b);
// void rr(t_stack *stack_a, t_stack *stack_b);
// void rra(t_stack *stack_a);
// void rrb(t_stack *stack_b);
// void rrr(t_stack *stack_a, t_stack *stack_b);