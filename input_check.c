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

void    check_empty_arg(char **argv, char **array)
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
        free(array);
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
            if ((argv[i][j] == '+' || argv[i][j] == '-') && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9') && (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\0'))
                j++;
            if (!digit(argv[i][j]) && !space(argv[i][j]))
            {
                free(array);
                write(2, "Error3\n", 7);
                exit(1);
            }
            j++;
        }
        i++;
    }
    check_empty_arg(argv, array);
}

int count_string(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] == '0')
            count++;
        i++;
    }
    return (count);
}

void    check_max_int(char **array)
{
    int i;
    long num;

    i = 0;
    while (array[i])
    {
        printf("strlen = %ld\n", ft_strlen(array[i]));
        printf("count = %d\n", count_string(array[i]));
        if (ft_strlen(array[i]) - count_string(array[i]) > 11)
        {
            ft_free(array);
            write(1, "Error5\n", 7);
            exit(1);
        }
        num = ft_atolong(array[i]);
        if (num > 2147483647 || num < -2147483648)
        {
            ft_free(array);
            write(1, "Error4\n", 7);
            exit(1);
        }
        i++;
    }
}

void fill_array(char **array, char **split, int j, int x)
{
    long num;
    int k;

    array[x] = ft_strdup(split[j]);
    if (array[x] == NULL)
    {
        ft_free(array);
        ft_free(split);
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
            fill_array(array, split, j, x);
            x++;
            j++;
        }
        i++;
        ft_free(split);
    }
    array[x] = NULL;
    check_max_int(array);
}
