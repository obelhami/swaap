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
    while (*a)
    {
        printf("%d\n", (*a)->nbr);
        *a = (*a)->next;
    }
}

int main(int argc, char **argv)
{
    char **array;
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
    ft_free(array);
    free_stack(&a);
    return (0);
}
