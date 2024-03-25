/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:16 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_intlist **stack_a)
{
	t_intlist	*last;
	t_intlist	*last2;

	if ((*stack_a)->next == NULL || *stack_a == NULL)
		return ;
	last = ft_intlstlast(*stack_a);
	last2 = *stack_a;
	while (last2->next != last)
		last2 = last2->next;
	last2->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	do_rra(t_intlist **stack_a)
{
	rra(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_intlist **stack_b)
{
	t_intlist	*last;
	t_intlist	*last2;

	if ((*stack_b)->next == NULL || *stack_b == NULL)
		return ;
	last = ft_intlstlast(*stack_b);
	last2 = *stack_b;
	while (last2->next != last)
		last2 = last2->next;
	last2->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	do_rrb(t_intlist **stack_b)
{
	rrb(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_intlist **stack_a, t_intlist **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
