/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:58:11 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 15:45:49 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_rotate_to_a(t_intlist *stack_a, t_intlist *stack_b)
{
	int			cost;
	t_intlist	*stack;

	stack = stack_b;
	cost = cost_to_a_rrarrb(stack_a, stack_b, stack_b->content);
	while (stack)
	{
		if (cost > cost_to_a_rarb(stack_a, stack_b, stack->content))
			cost = cost_to_a_rarb(stack_a, stack_b, stack->content);
		if (cost > cost_to_a_rrarrb(stack_a, stack_b, stack->content))
			cost = cost_to_a_rrarrb(stack_a, stack_b, stack->content);
		if (cost > cost_to_a_rarrb(stack_a, stack_b, stack->content))
			cost = cost_to_a_rarrb(stack_a, stack_b, stack->content);
		if (cost > cost_to_a_rrarb(stack_a, stack_b, stack->content))
			cost = cost_to_a_rrarb(stack_a, stack_b, stack->content);
		stack = stack->next;
	}
	return (cost);
}

int	choose_rotate_to_b(t_intlist *stack_a, t_intlist *stack_b)
{
	int			cost;
	t_intlist	*stack;

	stack = stack_a;
	cost = cost_to_b_rrarrb(stack_a, stack_b, stack_a->content);
	while (stack)
	{
		if (cost > cost_to_b_rarb(stack_a, stack_b, stack->content))
			cost = cost_to_b_rarb(stack_a, stack_b, stack->content);
		if (cost > cost_to_b_rrarrb(stack_a, stack_b, stack->content))
			cost = cost_to_b_rrarrb(stack_a, stack_b, stack->content);
		if (cost > cost_to_b_rarrb(stack_a, stack_b, stack->content))
			cost = cost_to_b_rarrb(stack_a, stack_b, stack->content);
		if (cost > cost_to_b_rrarb(stack_a, stack_b, stack->content))
			cost = cost_to_b_rrarb(stack_a, stack_b, stack->content);
		stack = stack->next;
	}
	return (cost);
}
