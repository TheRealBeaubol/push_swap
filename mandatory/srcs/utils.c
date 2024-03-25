/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:44:31 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_intlist **stack_a, char **split_val)
{
	ft_free_tab(split_val);
	ft_free_intlist(stack_a);
	ft_error();
}

long	ft_atol(char *nptr)
{
	long	i;
	long	stock;
	long	sign;

	sign = 1;
	i = 0;
	stock = 0;
	if ((nptr[i] == '-' || nptr[i] == '+') && ft_strlen(nptr) != 1)
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (9999999999);
		stock = (stock * 10) + (nptr[i] - 48);
		i++;
	}
	return (stock * sign);
}
