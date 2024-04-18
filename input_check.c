/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:37:19 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/14 16:37:20 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}

void    check_empty_arg(char **argv)
{
    int i;
    int j;
    int count;

    i = 1;
    while (argv[i])
    {
        j = 0;
        count = 0;
        while (argv[i][j])
        {
            if (digit(argv[i][j]))
                count++;
            // printf("count = %d\n", count);
            j++;
        }
        i++;
    }
    if (count == 0)
    {
        write(1, "Error8\n", 7);
        exit(1);
    }
}

void check_characters(char **argv, char **array)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j + 1] >= '0'
            && argv[i][j + 1] <= '9')
            && (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\0'))
                j++;
            if (!digit(argv[i][j]) && !space(argv[i][j]))
            {
                ft_free(array);
                write(2, "Error3\n", 7);
                exit(1);
            }
            j++;
        }
        i++;
    }
    check_empty_arg(argv);
}

void fill_tab(char **array, int size)
{
    int i;
    int tab[size];

    i = 0;
    if (array[1] == NULL)
    {
        ft_free(array);
        write(1, "Errorf\n", 7);
        exit(1);
    }
    while (i < size)
    {
        tab[i] = ft_atolong(array[i]);
        i++;
    }
    sort_tab(tab, size, array);
}

void sort_tab(int *tab, int size, char **array)
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
        ft_free(array);
        write(1, "Error9\n", 6);
        exit(1);
    }
}

void check_duplicate(char **array, char **split, int j, int x)
{
    long num;
    int k;

    num = ft_atolong(split[j]);
    k = 0;
    while (k < x)
    {
        if (num == ft_atolong(array[k]))
        {
            ft_free(split);
            ft_free(array);
            write(1, "Error6\n", 7);
            exit(1);
        }
        k++;
    }
    array[x] = ft_strdup(split[j]);
    if (array[x] == NULL)
    {
        write(1, "Error7\n", 7);
        exit(1);
    }
}
void check_args(int argc, char **argv, char **array)
{
    int i;
    int x;
    int j;
    char **split;

    i = 1;
    x = 0;
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        if (split == NULL)
            exit(1);
        j = 0;
        while (split[j])
        {
            check_duplicate(array, split, j, x);
            x++;
            j++;
        }
        i++;
    ft_free(split);
    }
    array[x] = NULL;
    fill_tab(array, x);
}
