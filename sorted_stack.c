/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:30 by obelhami          #+#    #+#             */
/*   Updated: 2024/04/22 11:40:32 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorted_stack(t_stack_node **a, t_stack_node **b, int size)
{
	sorted_two(a, size);
	sorted_three(a, size);
	sorted_four_five(a, b, size);
}