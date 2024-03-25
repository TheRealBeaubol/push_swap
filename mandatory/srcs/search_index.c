/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:24:16 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 15:45:38 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_index(t_intlist *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->content != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	search_index_in_b(t_intlist *stack_b, int nbr)
{
	int			i;
	t_intlist	*stack;

	i = 1;
	if (nbr > stack_b->content && nbr < ft_intlstlast(stack_b)->content)
		i = 0;
	else if (nbr > ft_lst_max(stack_b) || nbr < ft_lst_min(stack_b))
		i = search_index(stack_b, ft_lst_max(stack_b));
	else
	{
		stack = stack_b->next;
		while (stack_b->content < nbr || stack->content > nbr)
		{
			stack_b = stack_b->next;
			stack = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	search_index_in_a(t_intlist *stack_a, int nbr)
{
	int			i;
	t_intlist	*stack;

	i = 1;
	if (nbr < stack_a->content && nbr > ft_intlstlast(stack_a)->content)
		i = 0;
	else if (nbr > ft_lst_max(stack_a) || nbr < ft_lst_min(stack_a))
		i = search_index(stack_a, ft_lst_min(stack_a));
	else
	{
		stack = stack_a->next;
		while (stack_a->content > nbr || stack->content < nbr)
		{
			stack_a = stack_a->next;
			stack = stack_a->next;
			i++;
		}
	}
	return (i);
}
