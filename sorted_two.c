/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:46:40 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/22 11:46:41 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorted_two(t_stack_node **a, int size)
{
	t_stack_node *tmp;

	tmp = *a;
	if (size == 2)
	{
		write(1, "sa\n", 3);
		swap_a(a);
	}
}