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

void	check_instruction(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(line, "sa", 3))
		swap(a, "sa");
	else if (!ft_strncmp(line, "sb", 3))
		swap(b, "sb");
	else if (!ft_strncmp(line, "ss", 3))
	{
		swap(a, "ss");
		swap(b, "ss");
	}
	else if (!ft_strncmp(line, "pa", 3))
		push(a, b, "pa");
	else if (!ft_strncmp(line, "pb", 3))
		push(b, a, "pb");
	else if (!ft_strncmp(line, "ra", 3))
		rotate(a, "ra");
	else if (!ft_strncmp(line, "rb", 3))
		rotate(b, "rb");
	else if (!ft_strncmp(line, "rr", 3))
	{
		rotate(a, "rr");
		rotate(b, "rr");
	}
	else if (!ft_strncmp(line, "rra", 4))
		reverse_rotate(a, "rra");
	else if (!ft_strncmp(line, "rrb", 4))
		reverse_rotate(b, "rrb");
	else if (!ft_strncmp(line, "rrr", 4))
	{
		reverse_rotate(a, "rrr");
		reverse_rotate(b, "rrr");
	}
	else
	{
		free_stack(a);
		free_stack(b);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_string(t_stack_node **a, t_stack_node **b, char *line)
{
	
}

void	ft_checker(t_stack_node **a, t_stack_node **b, int *tab, int size)
{
	int	i;
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		check_string(a, b, line);
		line = get_next_line(0);
	}


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