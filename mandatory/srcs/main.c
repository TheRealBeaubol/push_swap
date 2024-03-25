/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:40:24 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 11:25:30 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_intlist	*stack_a;

	if (ac <= 1)
		ft_error();
	stack_a = make_list(av);
	if (stack_a == NULL)
		ft_error();
	if (is_list_sorted(stack_a) == 0)
		sort_main(&stack_a);
	ft_free_intlist(&stack_a);
	return (0);
}
