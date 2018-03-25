/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 08:08:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/24 23:39:54 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_ra(t_stacks *stacks)
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
	ft_putstr("ra\n");
 }

void	do_rb(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*current;

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
	ft_putstr("rb\n");
}

void	do_rra(t_stacks *stacks)
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
	ft_putstr("rra\n");
}

void	do_rrb(t_stacks *stacks)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!(current = stacks->b) || stacks->b->next == NULL)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
	current->next = NULL;
	ft_putstr("rrb\n");
}
