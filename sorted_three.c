/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:48:12 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/22 11:48:14 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorted_three(t_stack_node **a, int size)
{
	t_stack_node *tmp;

	tmp = *a;
	if (size == 3)
	{
		if (tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr)
			swap_a(a);
		else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
			&& tmp->next->nbr < tmp->next->next->nbr)
			rotate_a(a);
		else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
			&& tmp->next->nbr > tmp->next->next->nbr)
		{
			swap_a(a);
			reverse_rotate_a(a);
		}
		else if (tmp->nbr < tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
			&& tmp->next->nbr > tmp->next->next->nbr)
			reverse_rotate_a(a);
		else if (tmp->nbr < tmp->next->nbr && tmp->nbr < tmp->next->next->nbr
			&& tmp->next->nbr > tmp->next->next->nbr)
		{
			swap_a(a);
			rotate_a(a);
		}
	}
}