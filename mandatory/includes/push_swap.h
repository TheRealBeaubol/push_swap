/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 03:31:23 by lboiteux          #+#    #+#             */
/*   Updated: 2024/03/25 15:47:39 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void		pa(t_intlist **stack_a, t_intlist **stack_b);
void		do_pa(t_intlist **stack_a, t_intlist **stack_b);
void		pb(t_intlist **stack_a, t_intlist **stack_b);
void		do_pb(t_intlist **stack_a, t_intlist **stack_b);
void		ra(t_intlist **stack_a);
void		do_ra(t_intlist **stack_a);
void		rb(t_intlist **stack_b);
void		do_rb(t_intlist **stack_b);
void		do_rr(t_intlist **stack_a, t_intlist **stack_b);
void		rr(t_intlist **stack_a, t_intlist **stack_b);
void		rra(t_intlist **stack_a);
void		do_rra(t_intlist **stack_a);
void		rrb(t_intlist **stack_b);
void		do_rrb(t_intlist **stack_b);
void		do_rrr(t_intlist **stack_a, t_intlist **stack_b);
void		rrr(t_intlist **stack_a, t_intlist **stack_b);
void		sa(t_intlist **stack_a);
void		do_sa(t_intlist **stack_a);
void		sb(t_intlist **stack_b);
void		do_sb(t_intlist **stack_b);
void		do_ss(t_intlist **stack_a, t_intlist **stack_b);
void		ss(t_intlist **stack_a, t_intlist **stack_b);
void		sort_three_last_number_in_stack_a(t_intlist **stack_a);
int			check_double(t_intlist *stack_a, long number);
void		sort_main(t_intlist **stack_a);
void		keep_three_elt_in_stack_a(t_intlist **stack_a, t_intlist **stack_b);
int			is_list_sorted(t_intlist *stack);
int			rarrb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr);
int			rarrb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr);
int			rrarb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr);
int			rrarb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr);
int			rrarrb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, \
int nbr);
int			rrarrb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, \
int nbr);
int			rarb_and_push_a(t_intlist **stack_a, t_intlist **stack_b, int nbr);
int			rarb_and_push_b(t_intlist **stack_a, t_intlist **stack_b, int nbr);
int			choose_rotate_to_b(t_intlist *stack_a, t_intlist *stack_b);
int			choose_rotate_to_a(t_intlist *stack_a, t_intlist *stack_b);
int			search_index_in_a(t_intlist *stack_a, int nbr);
int			search_index_in_b(t_intlist *stack_b, int nbr);
int			search_index(t_intlist *stack, int nbr);
int			cost_to_a_rarb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_a_rrarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_a_rarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_a_rrarb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_b_rarb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_b_rrarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_b_rrarb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
int			cost_to_b_rarrb(t_intlist *stack_a, t_intlist *stack_b, int nbr);
t_intlist	**sort_stack_a(t_intlist **stack_a, t_intlist **stack_b);
t_intlist	*sort_stack_b(t_intlist **stack_a);
void		fill_list(t_intlist **stack_a, char **split_val);
t_intlist	*make_list(char **av);
long		ft_atol(char *nptr);
void		ft_free(t_intlist **stack_a, char **split_val);
#endif
