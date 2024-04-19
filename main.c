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

void    fill_tab(t_stack_node *a , int size)
{
    int i;
    int tab[size];

    i = 0;
    while (a)
    {
        tab[i] = a->nbr;
        a = a->next;
        i++;
    }
    i = 0;
    while (i < size)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    sort_tab(tab, size, a);
}

void sort_tab(int *tab, int size, t_stack_node *a)
{
    int i;
    int j;
    int number;

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
    if (number == 0)
    {
        free_stack(&a);
        write(1, "already sorted\n", 15);
        exit(1);
    }
}

int number_of_args(int argc, char **argv)
{
    int i;
    int j;
    int size;

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
void    check_double(t_stack_node **a)
{
    t_stack_node    *tmp;
    t_stack_node    *tmp2;

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

void init_stack(t_stack_node **a, char **array)
{
    int i;
    t_stack_node *new_node;
    t_stack_node *tmp;

    i = 0;
    while (array[i])
    {
        new_node = malloc(sizeof(t_stack_node));
        if (new_node == NULL)
            exit(1);
        new_node->nbr = ft_atolong(array[i]);
        new_node->next = NULL;
        if (*a == NULL)
            *a = new_node;
        else
        {
            tmp = *a;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new_node;
        }
        i++;
    }
    ft_free(array);
    check_double(a);
}

int main(int argc, char **argv)
{
    char **array;
    t_stack_node *a;
    t_stack_node *b;
    int i;

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
    i = node_size(a);
    fill_tab(a, i);
    free_stack(&a);
    return (0);
}
