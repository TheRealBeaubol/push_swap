/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:07:13 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 15:45:10 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_list(t_intlist **stack_a, char **split_val)
{
	long	nbr;
	int		j;

	j = 0;
	if (split_val[j] == NULL)
		ft_free(stack_a, split_val);
	while (split_val[j])
	{
		nbr = ft_atol(split_val[j++]);
		if (nbr > 2147483647 || nbr < -2147483648)
			ft_free(stack_a, split_val);
		if (check_double(*stack_a, nbr) == 0)
			ft_free(stack_a, split_val);
		ft_intlstadd_back(stack_a, ft_intlstnew((int)nbr));
	}
}

t_intlist	*make_list(char **av)
{
	int			i;
	t_intlist	*stack_a;
	char		**split_val;

	split_val = NULL;
	stack_a = NULL;
	i = 0;
	while (av[++i] != 0)
	{
		split_val = ft_str_split(av[i], " \f\n\r\t\v");
		fill_list(&stack_a, split_val);
		ft_free_tab(split_val);
	}
	return (stack_a);
}
