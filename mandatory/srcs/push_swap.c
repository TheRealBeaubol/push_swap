/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:09:30 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 15:45:26 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_last_number_in_stack_a(t_intlist **stack_a)
{
	if (ft_lst_min(*stack_a) == (*stack_a)->content)
	{
		do_rra(stack_a);
		do_sa(stack_a);
	}
	else if (ft_lst_max(*stack_a) == (*stack_a)->content)
	{
		do_ra(stack_a);
		if (is_list_sorted(*stack_a) == 0)
			do_sa(stack_a);
	}
	else
	{
		if (search_index(*stack_a, ft_lst_max(*stack_a)) == 1)
			do_rra(stack_a);
		else
			do_sa(stack_a);
	}
}

void	keep_three_elt_in_stack_a(t_intlist **stack_a, t_intlist **stack_b)
{
	int			cost;
	t_intlist	*stack;

	while (ft_intlstsize(*stack_a) > 3 && !is_list_sorted(*stack_a))
	{
		stack = *stack_a;
		cost = choose_rotate_to_b(*stack_a, *stack_b);
		while (cost >= 0)
		{
			if (cost == cost_to_b_rarb(*stack_a, *stack_b, stack->content))
				cost = rarb_and_push_b(stack_a, stack_b, stack->content);
			else if (cost == cost_to_b_rrarrb(*stack_a, *stack_b, \
			stack->content))
				cost = rrarrb_and_push_b(stack_a, stack_b, stack->content);
			else if (cost == cost_to_b_rarrb(*stack_a, *stack_b, \
			stack->content))
				cost = rarrb_and_push_b(stack_a, stack_b, stack->content);
			else if (cost == cost_to_b_rrarb(*stack_a, *stack_b, \
			stack->content))
				cost = rrarb_and_push_b(stack_a, stack_b, stack->content);
			else
				stack = stack->next;
		}
	}
}

t_intlist	*sort_stack_b(t_intlist **stack_a)
{
	t_intlist	*stack_b;

	stack_b = NULL;
	if (ft_intlstsize(*stack_a) > 3 && is_list_sorted(*stack_a) == 0)
		do_pb(stack_a, &stack_b);
	if (ft_intlstsize(*stack_a) > 3 && is_list_sorted(*stack_a) == 0)
		do_pb(stack_a, &stack_b);
	if (ft_intlstsize(*stack_a) > 3 && is_list_sorted(*stack_a) == 0)
		keep_three_elt_in_stack_a(stack_a, &stack_b);
	if (is_list_sorted(*stack_a) == 0)
		sort_three_last_number_in_stack_a(stack_a);
	return (stack_b);
}

t_intlist	**sort_stack_a(t_intlist **stack_a, t_intlist **stack_b)
{
	int			cost;
	t_intlist	*stack;

	while (*stack_b)
	{
		stack = *stack_b;
		cost = choose_rotate_to_a(*stack_a, *stack_b);
		while (cost >= 0)
		{
			if (cost == cost_to_a_rarb(*stack_a, *stack_b, stack->content))
				cost = rarb_and_push_a(stack_a, stack_b, stack->content);
			else if (cost == cost_to_a_rarrb(*stack_a, *stack_b, \
			stack->content))
				cost = rarrb_and_push_a(stack_a, stack_b, stack->content);
			else if (cost == cost_to_a_rrarrb(*stack_a, *stack_b, \
			stack->content))
				cost = rrarrb_and_push_a(stack_a, stack_b, stack->content);
			else if (cost == cost_to_a_rrarb(*stack_a, *stack_b, \
			stack->content))
				cost = rrarb_and_push_a(stack_a, stack_b, stack->content);
			else
				stack = stack->next;
		}
	}
	return (stack_a);
}

void	sort_main(t_intlist **stack_a)
{
	int			index;
	t_intlist	*stack_b;

	stack_b = NULL;
	if (ft_intlstsize(*stack_a) == 2)
		do_sa(stack_a);
	else
	{
		stack_b = sort_stack_b(stack_a);
		stack_a = sort_stack_a(stack_a, &stack_b);
		index = search_index(*stack_a, ft_lst_min(*stack_a));
		if (index < ft_intlstsize(*stack_a) - index)
			while ((*stack_a)->content != ft_lst_min(*stack_a))
				do_ra(stack_a);
		else
			while ((*stack_a)->content != ft_lst_min(*stack_a))
				do_rra(stack_a);
	}
}
