/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:55:48 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_a_rarb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = search_index_in_a(stack_a, nbr);
	if (search_index(stack_b, nbr) > cost)
		cost = search_index(stack_b, nbr);
	return (cost);
}

int	cost_to_a_rrarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = 0;
	if (search_index_in_a(stack_a, nbr) != 0)
		cost = ft_intlstsize(stack_a) - search_index_in_a(stack_a, nbr);
	if (((ft_intlstsize(stack_b) - search_index(stack_b, nbr)) > cost) \
	&& search_index(stack_b, nbr) != 0)
		cost = ft_intlstsize(stack_b) - search_index(stack_b, nbr);
	return (cost);
}

int	cost_to_a_rarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = 0;
	if (search_index(stack_b, nbr) != 0)
		cost = ft_intlstsize(stack_b) - search_index(stack_b, nbr);
	cost = search_index_in_a(stack_a, nbr) + cost;
	return (cost);
}

int	cost_to_a_rrarb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = 0;
	if (search_index_in_a(stack_a, nbr) != 0)
		cost = ft_intlstsize(stack_a) - search_index_in_a(stack_a, nbr);
	cost = search_index(stack_b, nbr) + cost;
	return (cost);
}
