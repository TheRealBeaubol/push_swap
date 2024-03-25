/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_and_push_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:58:49 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rarrb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while ((*stack_a)->content != nbr)
		do_ra(stack_a);
	while (search_index_in_b(*stack_b, nbr) > 0)
		do_rrb(stack_b);
	do_pb(stack_a, stack_b);
	return (-1);
}

int	rrarrb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while ((*stack_a)->content != nbr && search_index_in_b(*stack_b, nbr) > 0)
		do_rrr(stack_a, stack_b);
	while ((*stack_a)->content != nbr)
		do_rra(stack_a);
	while (search_index_in_b(*stack_b, nbr) > 0)
		do_rrb(stack_b);
	do_pb(stack_a, stack_b);
	return (-1);
}

int	rrarb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while ((*stack_a)->content != nbr)
		do_rra(stack_a);
	while (search_index_in_b(*stack_b, nbr) > 0)
		do_rb(stack_b);
	do_pb(stack_a, stack_b);
	return (-1);
}

int	rarb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while ((*stack_a)->content != nbr && search_index_in_b(*stack_b, nbr) > 0)
		do_rr(stack_a, stack_b);
	while ((*stack_a)->content != nbr)
		do_ra(stack_a);
	while (search_index_in_b(*stack_b, nbr) > 0)
		do_rb(stack_b);
	do_pb(stack_a, stack_b);
	return (-1);
}
