/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 06:33:15 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/22 10:15:42 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

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
		if (n > 2147483647 || n < -2147483648)
			put_error(2);
		stack_add(&stacks->a, stack_new((int)n));
	}
}
