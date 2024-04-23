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

int	position_min_tab(t_index *index, t_stack_node **a, int size_tab)
{
	int		i;
	t_stack_node	*tmp;

	tmp = (*a);
	i = 0;
	while (tmp)
	{
		if (tmp->nbr <= index->tab[size_tab])
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}


int	find_max_stack(t_stack_node **b)
{
	t_stack_node	*tmp;
	int	max;


	tmp = (*b);
	max = tmp->nbr;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

int	position_max_stack(t_stack_node **b)
{
	int		i;
	t_stack_node	*tmp;
	int	max;

	tmp = (*b);
	max = tmp->nbr;
	i = 0;
	while (tmp)
	{
		if (tmp->nbr == find_max_stack(b))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sorted_from_b(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		if (find_max_stack(b) == (*b)->nbr)
			push(a, b, "pa\n");
		else if (position_max_stack(b) > node_size((*b)) / 2)
			reverse_rotate(b, "rrb\n");
		else
			rotate(b, "rb\n");
	}

}

void	sorted_algo(t_index *index, t_stack_node **a, t_stack_node **b, int range)
{
	int	i;
	int	size_tab;


	i = 0;
	while (*a)
	{
		if (i + range < index->size)
			size_tab = i + range;
		if ((*a)->nbr >= index->tab[i] && (*a)->nbr <= index->tab[size_tab])
		{
			push(b, a, "pb\n");
			if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
				swap(b, "sb\n");
			i++;
		}
		else
		{
			if ((*a)->nbr <= index->tab[i])
			{
				push(b, a, "pb\n");
				rotate(b, "rb\n");
				i++;
			}
			else
			{
				if (position_min_tab(index, a, size_tab) > node_size(*a) / 2)
					reverse_rotate(a, "rra\n");
				else
					rotate(a, "ra\n");
			}
		}
	}
	sorted_from_b(a, b);
}

void	sorted_stack(t_stack_node **a, t_stack_node **b, int size, int *tab)
{
	t_index	*index;

	index = malloc(sizeof(t_index));
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
		sorted_algo(index, a, b, 3);
	else if (size > 30 && size <= 100)
		sorted_algo(index, a, b, 10);
	else if (size > 100 && size <= 500)
		sorted_algo(index, a, b, 30);
	else if (size > 500)
		sorted_algo(index, a, b, 39);
}