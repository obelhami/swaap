/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:25:52 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/14 16:25:54 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_tab(t_stack_node **a, int size)
{
	int				i;
	int				*tab;
	t_stack_node	*tmp;

	i = 0;
	tmp = *a;
	tab = malloc(sizeof(int) * size);
	while (tmp)
	{
		tab[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, size, a);
}
void	check_sort_tab(t_stack_node **a, int count, int *tab)
{
	if (count == 0)
	{
		free(tab);
		free_stack(a);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	sort_tab(int *tab, int size, t_stack_node **a)
{
	int	i;
	int	j;
	int	number;

	number = 0;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				ft_swap(&tab[i], &tab[j]);
				number++;
			}
			j++;
		}
		i++;
	}
	check_sort_tab(a, number, tab);
}

int	number_of_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (space(argv[i][j]) && argv[i][j + 1] != '\0')
				size++;
			j++;
		}
		size++;
		i++;
	}
	return (size);
}
void	check_double(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	tmp = *a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nbr == tmp2->nbr)
			{
				free_stack(a);
				write(2, "errordbl\n", 9);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	init_stack(t_stack_node **a, char **array)
{
	int				i;
	t_stack_node	*n_node;
	t_stack_node	*tmp;

	i = 0;
	while (array[i])
	{
		n_node = new_node(ft_atolong(array[i]));
		if (*a == NULL)
			*a = n_node;
		else
		{
			tmp = *a;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = n_node;
		}
		i++;
	}
	ft_free(array);
	check_double(a);
}
void	sorted_two(t_stack_node **a, int size)
{
	t_stack_node	*tmp;

	tmp = *a;
	if (size == 2)
	{
		write(1, "sa\n", 3);
		swap_a(a);
	}
}

void	sorted_three(t_stack_node **a, int size)
{
	t_stack_node	*tmp;

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

int	find_index(t_stack_node **a)
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
int	find_min(t_stack_node **a)
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
	t_stack_node	*tmp;
	int				i;

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

void	sorted_stack(t_stack_node **a, t_stack_node **b, int size)
{
	sorted_two(a, size);
	sorted_three(a, size);
	sorted_four_five(a, b, size);
}

int	main(int argc, char **argv)
{
	int				size;
	char			**array;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	size = number_of_args(argc, argv);
	array = malloc(sizeof(char *) * (number_of_args(argc, argv) + 1));
	if (!array)
		return (0);
	check_characters(argv, array);
	check_args(argc, argv, array);
	init_stack(&a, array);
	fill_tab(&a, number_of_args(argc, argv));
	sorted_stack(&a, &b, size);
	free_stack(&a);
	return (0);
}
