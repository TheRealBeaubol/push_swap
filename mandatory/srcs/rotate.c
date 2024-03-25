/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:16 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_intlist **stack_a)
{
	t_intlist	*stack;

	if ((*stack_a)->next == NULL || *stack_a == NULL)
		return ;
	stack = ft_intlstlast(*stack_a);
	stack->next = *stack_a;
	*stack_a = (*stack_a)->next;
	stack->next->next = NULL;
}

void	do_ra(t_intlist **stack_a)
{
	ra(stack_a);
	ft_printf("ra\n");
}

void	rb(t_intlist **stack_b)
{
	t_intlist	*stack;

	if ((*stack_b)->next == NULL || *stack_b == NULL)
		return ;
	stack = ft_intlstlast(*stack_b);
	stack->next = *stack_b;
	*stack_b = (*stack_b)->next;
	stack->next->next = NULL;
}

void	do_rb(t_intlist **stack_b)
{
	rb(stack_b);
	ft_printf("rb\n");
}

void	rr(t_intlist **stack_a, t_intlist **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
