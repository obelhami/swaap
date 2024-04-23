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



void	sorted_stack(t_stack_node **a, t_stack_node **b, int size, int *tab)
{
	t_index	*index;

	index = malloc(sizeof(t_index));
	index->a = a;
	index->b = b;
	index->size = size;
	index->tab = tab;
	index->range = 0;
	if (size == 2)
		sorted_two(a, size);
	else if (size == 3)
		sorted_three(a, size);
	else if (size == 4 || size == 5)
		sorted_four_five(a, b);
	else if (size > 5 && size <= 30)

	else if (size > 30 && size <= 100)
		sorted_algo(index, 10);
	else if (size > 100 && size <= 500)
		sorted_algo(index, 30);
	else if (size > 500)
		sorted_algo(index, 39);
}