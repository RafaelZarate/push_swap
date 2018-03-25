/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:33:15 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/24 21:55:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	search_equals(t_stacks *stacks, int num)
{
	t_stack	*current;

	current = stacks->a;
	while (current)
	{
		if (current->n == num)
			put_error(3);
		current = current->next;
	}
}

void	parser(t_stacks *stacks, char **input, int ac)
{
	int			i;
	intmax_t	n;

	stacks->length_a = ac - 1;
	while (--ac > 0)
	{
		i = -1;
		while (input[ac][++i])
		{
			if (!ft_isdigit(input[ac][i]))
				put_error(1);
		}
		n = ft_atoi(input[ac]);
		search_equals(stacks, n);
		if (n > INT_MAX || n < INT_MIN)
			put_error(2);
		stack_add(&stacks->a, stack_new((int)n));
	}
}

void	get_current_position(t_stacks *stacks)
{
	t_stack *a;
	t_stack *b;

	a = stacks->a;
	b = stacks->b;
	if (a)
	{
		stacks->a_first = a->n;
		if (a->next)
		{
			stacks->a_second = a->next->n;
			while(a->next)
				a = a->next;
			stacks->a_last = a->n;
		}
	}
	if (b)
	{
		stacks->b_first = b->n;
		if (b->next)
		{
			stacks->b_second = b->next->n;
			while(b->next)
				b = b->next;
			stacks->b_last = b->n;
		}
	}
	get_min_max(stacks);
}

int	check_if_rev_sorted(t_stacks *stacks)
{
	t_stack	*b;
	int c;

	c = 0;
	b = stacks->b;
	if (b == NULL)
		return (0);
	else
	{
		while (b->next != NULL)
		{
			c++;
			if (b->n < b->next->n)
				return (c);
			b = b->next;
		}
		return (0);
	}
}

int	check_if_sorted(t_stacks *stacks)
{
	t_stack	*a;

	a = stacks->a;
	if (a == NULL)
		return (0);
	else
	{
		while (a->next != NULL)
		{
			if (a->n > a->next->n)
				return (0);
			a = a->next;
		}
		return (1);
	}
}
