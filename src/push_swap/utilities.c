/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:56:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/22 10:15:24 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	put_error(int n)
{
	ft_putstr_fd("Error", 2);
	exit (n);
}

void	do_ss(t_stacks *stacks)
{
	do_sa(stacks);
	do_sb(stacks);
}

void	do_rr(t_stacks *stacks)
{
	do_ra(stacks);
	do_rb(stacks);
}

void	do_rrr(t_stacks *stacks)
{
	do_rra(stacks);
	do_rrb(stacks);
}

void	handle_ops(char *operations, t_stacks *stacks)
{
	if (ft_strcmp(operations, "sa") == 0)
		do_sa(stacks);
	else if (ft_strcmp(operations, "sb") == 0)
		do_sb(stacks);
	else if (ft_strcmp(operations, "pa") == 0)
		do_pa(stacks);
	else if (ft_strcmp(operations, "pb") == 0)
		do_pb(stacks);
	else if (ft_strcmp(operations, "ra") == 0)
		do_ra(stacks);
	else if (ft_strcmp(operations, "rb") == 0)
		do_rb(stacks);
	else if (ft_strcmp(operations, "rra") == 0)
		do_rra(stacks);
	else if (ft_strcmp(operations, "rrb") == 0)
		do_rrb(stacks);
	else if (ft_strcmp(operations, "ss") == 0)
		do_ss(stacks);
	else if (ft_strcmp(operations, "rr") == 0)
		do_rr(stacks);
	else if (ft_strcmp(operations, "rrr") == 0)
		do_rrr(stacks);
	else
		put_error(4);
}
