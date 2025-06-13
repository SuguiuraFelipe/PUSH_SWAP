/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:24:36 by fsuguiur          #+#    #+#             */
/*   Updated: 2025/06/13 21:38:58 by fsuguiur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"



int main(int ac, char **av)
{
    int i = 1;

    if (ac < 2)
    {
        printf("Faltou argumento\n");
        return 1;
    }
    while (av[i])
    {
        t_node *node = create_node(atoi(av[i]));
        printf("%i\n", node->value);
        node = node->next;
        i++; 
    }
    return 0;
}
