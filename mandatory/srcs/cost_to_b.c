/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:55:45 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_b_rarb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = search_index_in_b(stack_b, nbr);
	if (search_index(stack_a, nbr) > cost)
		cost = search_index(stack_a, nbr);
	return (cost);
}

int	cost_to_b_rrarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = 0;
	if (search_index_in_b(stack_b, nbr) != 0)
		cost = ft_intlstsize(stack_b) - search_index_in_b(stack_b, nbr);
	if (((ft_intlstsize(stack_a) - search_index(stack_a, nbr)) > cost) \
		&& search_index(stack_a, nbr) != 0)
		cost = ft_intlstsize(stack_a) - search_index(stack_a, nbr);
	return (cost);
}

int	cost_to_b_rrarb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = 0;
	if (search_index(stack_a, nbr) != 0)
		cost = ft_intlstsize(stack_a) - search_index(stack_a, nbr);
	cost = search_index_in_b(stack_b, nbr) + cost;
	return (cost);
}

int	cost_to_b_rarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr)
{
	int	cost;

	cost = 0;
	if (search_index_in_b(stack_b, nbr) != 0)
		cost = ft_intlstsize(stack_b) - search_index_in_b(stack_b, nbr);
	cost = search_index(stack_a, nbr) + cost;
	return (cost);
}
