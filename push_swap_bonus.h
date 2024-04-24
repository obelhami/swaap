/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:49 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/24 16:31:52 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	struct s_stack_node	*next;
}						t_stack_node;

void					ft_free(char **array);
void					check_args(int argc, char **argv, char **array);
long					ft_atolong(const char *str);
int						*fill_tab(t_stack_node **a, int i);
void					init_stack(t_stack_node **a, char **array);
void					sort_tab(int *tab, int size, t_stack_node **a);
void					check_characters(char **argv, char **array);
void					ft_swap(int *a, int *b);
int						space(char c);
int						number_of_args(int argc, char **argv);
void					push(t_stack_node **a, t_stack_node **b, char *str);
void					swap(t_stack_node **a, char *str);
void					rotate(t_stack_node **a, char *str);
void					reverse_rotate(t_stack_node **a, char *str);
void					free_stack(t_stack_node **a);
int						count_string(char *str);
void					check_max_int(char **array);
void					fill_array(char **array, char **split, int j, int x);
void					check_empty_arg(char **argv, char **array);
void					check_sort_tab(t_stack_node **a, int count, int *tab);
int						node_size(t_stack_node *lst);
t_stack_node			*new_node(long content, char **array);

#endif