/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:08:43 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/22 10:38:57 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	do_sa(t_stacks *stacks)
{
	t_stack *tmp1;
	t_stack *tmp2;

	if (!(tmp1 = stacks->a))
		return ;
	if ((tmp2 = tmp1->next))
	{
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		stacks->a = tmp2;
	}
}

void	do_sb(t_stacks *stacks)
{
	t_stack *tmp1;
	t_stack *tmp2;

	if (!(tmp1 = stacks->b))
		return ;
	if ((tmp2 = tmp1->next))
	{
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		stacks->b = tmp2;
	}
}

void	do_pb(t_stacks *stacks)
{
	t_stack *tmp;
	// t_stack *tmp2;
	
	if ((tmp = stacks->a))
	{
		stacks->a = stacks->a->next;
		tmp->next = stacks->b;
		stacks->b = tmp;
		stacks->length_a--;
		stacks->length_b++;
	}
}

void	do_pa(t_stacks *stacks)
{
	t_stack *tmp;
	// t_stack *tmp2;
	
	if ((tmp = stacks->b))
	{
		stacks->b = stacks->b->next;
		tmp->next = stacks->a;
		stacks->a = tmp;
		stacks->length_a++;
		stacks->length_b--;
	}
}
