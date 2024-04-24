/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:27 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 16:31:30 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

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
				write(2, "Error\n", 6);
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
		n_node = new_node(ft_atolong(array[i]), array);
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_string(t_stack_node **a, t_stack_node **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
	{
		free_stack(a);
		free_stack(b);
		free(line);
		exit(write(2, "Error\n", 6));
	}
}

void	ft_checker(t_stack_node **a, t_stack_node **b, int *tab, int size)
{
	int	i;
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_string(a, b, line);
		free(line);
	}
	i = 0;
	while (i < size)
	{
		if (tab[i] != (*a)->nbr)
		{
			free_stack(a);
			free_stack(b);
			free(tab);
			exit(write(1, "KO\n", 3));
		}
		rotate(a);
		i++;
	}
	free_stack(a);
	free_stack(b);
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	char **array;
	int *tab;
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	array = malloc(sizeof(char *) * (number_of_args(argc, argv) + 1));
	if (!array)
		return (0);
	check_characters(argv, array);
	check_args(argc, argv, array);
	init_stack(&a, array);
	tab = fill_tab(&a, number_of_args(argc, argv));
	ft_checker(&a, &b, tab, number_of_args(argc, argv));
	free(tab);
	free_stack(&a);
	return (0);
}