/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_four_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:52:30 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/22 11:55:52 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	find_index(t_stack_node **a)
{
	t_stack_node	*tmp;
	int				min;
	int				i;

	i = 0;
	tmp = *a;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	find_min(t_stack_node **a)
{
	int				min;
	t_stack_node	*tmp;

	tmp = *a;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

void	sorted_four_five(t_stack_node **a, t_stack_node **b, int size)
{
	int				i;
	t_stack_node	*tmp;

	tmp = *a;
	i = 0;
	while (node_size(*a) > 3)
	{
		if ((*a)->nbr == find_min(a))
			push_b(a, b);
		else if (find_index(a) > node_size(*a) / 2)
			reverse_rotate_a(a);
		else
			rotate_a(a);
	}
	sorted_three(a, node_size(*a));
	push_a(a, b);
	push_a(a, b);
}
