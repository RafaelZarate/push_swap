/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:56:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/23 09:25:56 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	put_error(int n)
{
	ft_putstr_fd("Error", 2);
	exit (n);
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

void	print_stacks(t_stacks *stacks)
{
	ft_putstr("Stack A: ");
	t_stack *a;
	a = stacks->a;
	while (a)
	{
		ft_putnbr(a->n);
		ft_putchar(' ');
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("Stack B: ");
	t_stack *b;
	b = stacks->b;
	while (b)
	{
		ft_putnbr(b->n);
		ft_putchar(' ');
		b = b->next;
	}
	ft_putchar('\n');
}

void	get_min_max(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;
	int		min;
	int		max;

	max = INT_MIN;
	min = INT_MAX;
	a = stacks->a;
	b = stacks->b;
	while (a)
	{
		if (a->n > max)
			max = a->n;
		if (a->n < min)
			min = a->n;
		a = a->next;
	}
	max = INT_MIN;
	min = INT_MAX;
	while (b)
	{
		if (b->n > max)
			max = b->n;
		if (b->n < min)
			min = b->n;
		b = b->next;
	}
}