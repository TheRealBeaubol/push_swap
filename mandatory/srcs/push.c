/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:01 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*top_stack_b;

	if (stack_b == NULL)
		return ;
	top_stack_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_stack_b->next = *stack_a;
	*stack_a = top_stack_b;
}

void	do_pa(t_intlist **stack_a, t_intlist **stack_b)
{
	ft_printf("pa\n");
	pa(stack_a, stack_b);
}

void	pb(t_intlist **stack_a, t_intlist **stack_b)
{
	t_intlist	*top_stack_a;

	if (stack_a == NULL)
		return ;
	top_stack_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_stack_a->next = *stack_b;
	*stack_b = top_stack_a;
}

void	do_pb(t_intlist **stack_a, t_intlist **stack_b)
{
	ft_printf("pb\n");
	pb(stack_a, stack_b);
}
