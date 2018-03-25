/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 05:16:50 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/25 01:33:23 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_ss(t_stacks *stacks)
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
	if (!(tmp1 = stacks->b))
		return ;
	if ((tmp2 = tmp1->next))
	{
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		stacks->b = tmp2;
	}
	ft_putstr("ss\n");
}

void	do_rr(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*current;


	if (!(tmp = stacks->a))
		return ;
	if (stacks->a->next != NULL)
	{
		stacks->a = stacks->a->next;
		current = stacks->a;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	if (!(tmp = stacks->b))
		return ;
	if (stacks->b->next != NULL)
	{
		stacks->b = stacks->b->next;
		current = stacks->b;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	ft_putstr("rr\n");
}

void	do_rrr(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!(current = stacks->a) || stacks->a->next == NULL)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
	current->next = NULL;
	if (!(current = stacks->b) || stacks->b->next == NULL)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
	current->next = NULL;
	ft_putstr("rrr\n");
}