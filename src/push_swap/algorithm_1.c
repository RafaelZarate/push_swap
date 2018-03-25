/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 03:48:45 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/25 03:49:06 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_b_1(t_stacks *stacks, char **b_op)
{
	if (stacks->b)
	{
		get_current_position(stacks);
		if (stacks->b_first < stacks->min_b)
			*b_op = ft_strdup("rb");
		else if (stacks->b_first < stacks->b_second)
			*b_op = ft_strdup("sb");
		else if (stacks->b_last > stacks->b_second)
			*b_op = ft_strdup("rrb");
		else
			*b_op = NULL;
	}
	else
		*b_op = NULL;
}

void	sort_a_1(t_stacks *stacks, char **a_op)
{
	if (stacks->a)
	{
		get_current_position(stacks);
		if (stacks->a_first == stacks->max_a)
			*a_op = ft_strdup("ra");
		else if (stacks->a_first > stacks->a_second)
			*a_op = ft_strdup("sa");
		else if (stacks->a_last < stacks->a_second)
			*a_op = ft_strdup("rra");
		else
		{
			*a_op = ft_strdup("pb");
		}
	}
}

void	return_to_a_1(t_stacks *stacks)
{
	while (stacks->b)
	{
		get_current_position(stacks);
		if (stacks->b_first == stacks->max_b)
			handle_ops("pa", stacks);
		else if (stacks->b_last == stacks->max_b)
		{
			handle_ops("rrb", stacks);
			handle_ops("pa", stacks);
		}
		else if (stacks->b_second == stacks->max_b)
		{
			handle_ops("sb", stacks);
			handle_ops("pa", stacks);
		}
		else
		{
			stacks->max_b_pos = get_position_of_max(stacks);
			stacks->length_b += (stacks->length_b % 2 == 0) ? 0 : 1;
			if (stacks->max_b_pos <= (stacks->length_b / 2))
			{
				while (--stacks->max_b_pos)
					handle_ops("rb", stacks);
			}
			else
			{
				stacks->max_b_pos = stacks->length_b - stacks->max_b_pos + 2;
				while (--stacks->max_b_pos)
					handle_ops("rrb", stacks);
			}
			handle_ops("pa", stacks);
		}
	}
}
