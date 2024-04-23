/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:30 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/22 11:40:32 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// void	sorted_algo(t_stack_node **a, t_stack_node **b, int size, int *tab)
// {
// 	printf("size = %d\n", size);
	
// }

void	sorted_stack(t_stack_node **a, t_stack_node **b, int size, int *tab)
{
	if (size == 2)
		sorted_two(a, size);
	else if (size == 3)
		sorted_three(a, size);
	else if (size == 4 || size == 5)
		sorted_four_five(a, b);
	// sorted_algo(a, b, size, tab);
	int	i;
	i = 0;
	while (i < size)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}