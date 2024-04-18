/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:54:54 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/15 16:54:56 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "./libft/libft.h"

typedef struct s_index
{
    int i;
    int j;
    int x;
    int size;
    int k;
} t_index;

typedef struct s_stack_node
{
    int nbr;
    struct s_stack_node *next;
} t_stack_node;

void    ft_free(char **array);
void    check_args(int argc, char **argv, char **array);
long    ft_atolong(const char *str);
void    fill_tab(char **array, int size);
void    init_stack(t_stack_node **a, char **array);
void    sort_tab(int *tab, int size, char **array);
void    check_characters(char **argv, char **array);
void    ft_swap(int *a, int *b);
int     space(char c);
int     number_of_args(int argc, char **argv);
void    swap_a(t_stack_node **a);
void    swap_b(t_stack_node **b);
void    swap_s(t_stack_node **a, t_stack_node **b);
void    push_a(t_stack_node **a, t_stack_node **b);
void    push_b(t_stack_node **a, t_stack_node **b);
void    rotate_a(t_stack_node **a);
void    rotate_b(t_stack_node **b);
void    rotate_r(t_stack_node **a, t_stack_node **b);
void    reverse_rotate_a(t_stack_node **a);
void    reverse_rotate_b(t_stack_node **b);
void    reverse_rotate_r(t_stack_node **a, t_stack_node **b);
void    free_stack(t_stack_node **a);

#endif
