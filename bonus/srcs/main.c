/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:04:52 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 15:48:31 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_intlist **stack_a, t_intlist **stack_b, char *tmp)
{
	if (tmp[1] == 'a')
		sa(stack_a);
	else if (tmp[1] == 'b')
		sb(stack_b);
	else if (tmp[1] == 's')
		ss(stack_a, stack_b);
	else
	{
		ft_free_intlist(stack_a);
		ft_free_intlist(stack_b);
		free(tmp);
		ft_error();
	}
}

void	instru(t_intlist **stack_a, t_intlist **stack_b, char *tmp)
{
	if (tmp[0] == 's' && tmp[2] == '\n')
		swap(stack_a, stack_b, tmp);
	else if (tmp[0] == 'p' && tmp[1] == 'a' && tmp[2] == '\n')
		pa(stack_a, stack_b);
	else if (tmp[0] == 'p' && tmp[1] == 'b' && tmp[2] == '\n')
		pb(stack_a, stack_b);
	else if (tmp[0] == 'r' && tmp[1] == 'a' && tmp[2] == '\n')
		ra(stack_a);
	else if (tmp[0] == 'r' && tmp[1] == 'b' && tmp[2] == '\n')
		rb(stack_b);
	else if (tmp[0] == 'r' && tmp[1] == 'r' && tmp[2] == '\n')
		rr(stack_a, stack_b);
	else if (tmp[0] == 'r' && tmp[1] == 'r' && tmp[2] == 'a' && tmp[3] == '\n')
		rra(stack_a);
	else if (tmp[0] == 'r' && tmp[1] == 'r' && tmp[2] == 'b' && tmp[3] == '\n')
		rrb(stack_b);
	else if (tmp[0] == 'r' && tmp[1] == 'r' && tmp[2] == 'r' && tmp[3] == '\n')
		rrr(stack_a, stack_b);
	else
	{
		ft_free_intlist(stack_a);
		ft_free_intlist(stack_b);
		free(tmp);
		ft_error();
	}
}

void	do_instructions(t_intlist **stack_a, t_intlist **stack_b, char *str)
{
	char	*tmp;

	while (str && *str != '\n')
	{
		tmp = str;
		instru(stack_a, stack_b, tmp);
		str = get_next_line(0, 0);
		free(tmp);
	}
	free(str);
}

void	checker(t_intlist **stack_a)
{
	t_intlist	*stack_b;
	char		*str;

	stack_b = NULL;
	str = get_next_line(0, 0);
	if (str == NULL && is_list_sorted(*stack_a) == 0)
		ft_printf("KO\n");
	else if (str == NULL && is_list_sorted(*stack_a) == 1)
		ft_printf("OK\n");
	else
	{
		do_instructions(stack_a, &stack_b, str);
		if (stack_b == NULL && is_list_sorted(*stack_a) == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_free_intlist(&stack_b);
}

int	main(int ac, char **av)
{
	t_intlist	*stack_a;

	stack_a = NULL;
	if (ac <= 1)
		ft_error();
	stack_a = make_list(av);
	checker(&stack_a);
	ft_free_intlist(&stack_a);
	return (0);
}
