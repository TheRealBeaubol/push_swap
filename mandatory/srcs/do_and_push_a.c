/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_and_push_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:58:29 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rarb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while ((*stack_b)->content != nbr && search_index_in_a(*stack_a, nbr) > 0)
		do_rr(stack_a, stack_b);
	while ((*stack_b)->content != nbr)
		do_rb(stack_b);
	while (search_index_in_a(*stack_a, nbr) > 0)
		do_ra(stack_a);
	do_pa(stack_a, stack_b);
	return (-1);
}

int	rrarrb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while ((*stack_b)->content != nbr && search_index_in_a(*stack_a, nbr) > 0)
		do_rrr(stack_a, stack_b);
	while ((*stack_b)->content != nbr)
		do_rrb(stack_b);
	while (search_index_in_a(*stack_a, nbr) > 0)
		do_rra(stack_a);
	do_pa(stack_a, stack_b);
	return (-1);
}

int	rrarb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while (search_index_in_a(*stack_a, nbr) > 0)
		do_rra(stack_a);
	while ((*stack_b)->content != nbr)
		do_rb(stack_b);
	do_pa(stack_a, stack_b);
	return (-1);
}

int	rarrb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr)
{
	while (search_index_in_a(*stack_a, nbr) > 0)
		do_ra(stack_a);
	while ((*stack_b)->content != nbr)
		do_rrb(stack_b);
	do_pa(stack_a, stack_b);
	return (-1);
}
