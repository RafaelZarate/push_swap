/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 23:50:10 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/23 09:32:27 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_b(t_stacks *stacks)
{
	int	first;
	int	second;
	int	last;

	if (stacks->b)
	{
		while (!check_if_rev_sorted(stacks))
		{
			get_current_position(stacks);
			first = stacks->b_first;
			second = stacks->b_second;
			last = stacks->b_last;
			if (first < second && first < last)
				do_rb(stacks);
			else if (first < second && first > last)
				do_sb(stacks);
			else if (last > first && last > second)
				do_rrb(stacks);
			else
			{
				while (!(first < second && first > last))
				{
					get_current_position(stacks);
					first = stacks->b_first;
					second = stacks->b_second;
					last = stacks->b_last;
					do_rrb(stacks);
				}
			}
			print_stacks(stacks);
			// ft_putstr("LOLB");
		}
		while (stacks->b)  
		{
			do_pa(stacks);
			print_stacks(stacks);
		}
	}
}



void	sort_a(t_stacks *stacks)
{
	int	first;
	int	second;
	int	last;

	while (!check_if_sorted(stacks))// && (stacks->a_first > stacks->b_first))
	{
		get_current_position(stacks);
		first = stacks->a_first;
		second = stacks->a_second;
		last = stacks->a_last;
		if (first > second && first > last)
			do_ra(stacks);
		else if (last < first && last < second)
			do_rra(stacks);
		else if (first > second && first < last)
			do_sa(stacks);
		else
			do_pb(stacks);
		print_stacks(stacks);
		// ft_putstr("LOLA");
	}
}

void			solver(t_stacks *stacks)
{
	ft_putstr("Initial stack: ");
	t_stack *a;
	a = stacks->a;
	while (a)
	{
		ft_putnbr(a->n);
		a = a->next;
	}
	ft_putchar('\n');
	sort_a(stacks);
	sort_b(stacks);
	// while(stacks->a)
	// {
	// 	ft_putnbr(stacks->a->n);
	// 	stacks->a = stacks->a->next;
	// }
}
