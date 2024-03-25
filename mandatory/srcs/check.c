/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:40:32 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_intlist *stack_a, long number)
{
	int	nbr;

	nbr = (int)number;
	while (stack_a)
	{
		if (stack_a->content == nbr)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_list_sorted(t_intlist *stack)
{
	int	value;

	value = stack->content;
	while (stack)
	{
		if (value > stack->content)
			return (0);
		value = stack->content;
		stack = stack->next;
	}
	return (1);
}
