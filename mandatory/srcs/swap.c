/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:15:08 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:55 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_intlist **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ft_int_swap(&(*stack_a)->content, &(*stack_a)->next->content);
}

void	do_sa(t_intlist **stack_a)
{
	sa(stack_a);
	ft_printf("sa\n");
}

void	sb(t_intlist **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ft_int_swap(&(*stack_b)->content, &(*stack_b)->next->content);
}

void	do_sb(t_intlist **stack_b)
{
	sb(stack_b);
	ft_printf("sb\n");
}

void	ss(t_intlist **stack_a, t_intlist **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
