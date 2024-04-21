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

void fill_tab(t_stack_node **a, int size)
{
    int i;
    int tab[size];
    t_stack_node *tmp;

    i = 0;
    tmp = *a;
    while (tmp)
    {
        tab[i] = tmp->nbr;
        tmp = tmp->next;
        i++;
    }
    i = 0;
    while (i < size)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
        i++;
    }
    sort_tab(tab, size, a);
}

void sort_tab(int *tab, int size, t_stack_node **a)
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
        free_stack(a);
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
void check_double(t_stack_node **a)
{
    t_stack_node *tmp;
    t_stack_node *tmp2;

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
    t_stack_node *n_node;
    t_stack_node *tmp;

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
void    sorted_two(t_stack_node **a, int size)
{
    t_stack_node *tmp;

    tmp = *a;
    if (size == 2)
    {
        write(1, "sa\n", 3);
        swap_a(a);
    }
}

void handle_swap_and_rotate(t_stack_node **a, t_stack_node *tmp)
{
    if (tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr)
    {
        write(1, "sa\n", 3);
        swap_a(a);
    }
    else if (tmp->nbr < tmp->next->nbr && tmp->nbr < tmp->next->next->nbr
        && tmp->next->nbr > tmp->next->next->nbr)
    {
        write(1, "sa\n", 3);
        swap_a(a);
        write(1, "ra\n", 3);
        rotate_a(a);
    }
}

void handle_rotate_and_reverse(t_stack_node **a, t_stack_node *tmp)
{
    if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
        && tmp->next->nbr < tmp->next->next->nbr)
    {
        write(1, "ra\n", 3);
        rotate_a(a);
    }
    else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
        && tmp->next->nbr > tmp->next->next->nbr)
    {
        write(1, "sa\n", 3);
        swap_a(a);
        write(1, "rra\n", 4);
        reverse_rotate_a(a);
    }
    else if (tmp->nbr < tmp->next->nbr && tmp->nbr > tmp->next->next->nbr
        && tmp->next->nbr > tmp->next->next->nbr)
    {
        write(1, "rra\n", 4);
        reverse_rotate_a(a);
    }
}

void sorted_three(t_stack_node **a, int size)
{
    t_stack_node *tmp;

    tmp = *a;
    if (size == 3)
    {
        handle_swap_and_rotate(a, tmp);
        handle_rotate_and_reverse(a, tmp);
    }
}
// void    sorted_three(t_stack_node **a, int size)
// {
//     t_stack_node *tmp;

//     tmp = *a;
//     if (size == 3)
//     {
//         if (tmp->nbr > tmp->next->nbr && tmp->nbr < tmp->next->next->nbr)
//         {
//             write(1, "sa\n", 3);
//             swap_a(a);
//         }
//         else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr && tmp->next->nbr < tmp->next->next->nbr)
//         {
//             write(1, "ra\n", 3);
//             rotate_a(a);
//         }
//         else if (tmp->nbr > tmp->next->nbr && tmp->nbr > tmp->next->next->nbr && tmp->next->nbr > tmp->next->next->nbr)
//         {
//             write(1, "sa\n", 3);
//             swap_a(a);
//             write(1, "rra\n", 4);
//             reverse_rotate_a(a);
//         }
//         else if (tmp->nbr < tmp->next->nbr && tmp->nbr > tmp->next->next->nbr && tmp->next->nbr > tmp->next->next->nbr)
//         {
//             write(1, "rra\n", 4);
//             reverse_rotate_a(a);
//         }
//         else if (tmp->nbr < tmp->next->nbr && tmp->nbr < tmp->next->next->nbr && tmp->next->nbr > tmp->next->next->nbr)
//         {
//             write(1, "sa\n", 3);
//             swap_a(a);
//             write(1, "ra\n", 3);
//             rotate_a(a);
//         }
//     }
// }

// void    search_smallest(t_stack_node *tmp, t_stack_node **a, t_stack_node **b)
// {
//     int i;
//     int j;
//     int smallest;
//     t_stack_node *tmp2;

//     i = 0;
//     j = 0;
//     smallest = tmp->nbr;
//     tmp2 = tmp;
//     while (tmp)
//     {
//         if (tmp->nbr < smallest)
//         {
//             smallest = tmp->nbr;
//             tmp2 = tmp;
//         }
//         tmp = tmp->next;
//         i++;
//     }
//     while (j < i)
//     {
//         if (tmp2->nbr == (*a)->nbr)
//         {
//             write(1, "pb\n", 3);
//             push_b(a, b);
//             break;
//         }
//         write(1, "ra\n", 3);
//         rotate_a(a);
//         j++;
//     }
// }

void    find_min(t_stack_node *tmp, t_stack_node **a, t_stack_node **b, int size)
{

    int smallest;
    t_stack_node *tmp2;

    smallest = tmp->nbr;
    tmp = tmp->next;
    while (tmp)
    {
        if (smallest == tmp->nbr)
            smallest = tmp->nbr;
        tmp = tmp -> next;
    }
    tmp = *a;
    while (tmp)
    {
        if (tmp->nbr == smallest)
        {
            write(1, "pb\n", 3);
            push_b(a, b);
            break;
        }
        tmp = tmp->next;
    }
}


void    sorted_four_five(t_stack_node **a, t_stack_node **b, int size)
{
    t_stack_node *tmp;
    int i;
    int smallest;

    i = 0;
    tmp = *a;
    while (size > 3)
    {
        find_min(tmp, a, b, size);
        size--;
    }
    sorted_three(a, size);
    push_a(a, b);
    write(1, "pa\n", 3);
    push_a(a, b);
    write(1, "pa\n", 3);
}

void sorted_stack(t_stack_node **a, t_stack_node **b, int size)
{
    sorted_two(a, size);
    sorted_three(a, size);
    sorted_four_five(a, b, size);
}

int main(int argc, char **argv)
{
    int size;
    char **array;
    t_stack_node *a;
    t_stack_node *b;

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
