/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/26 12:04:16 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

t_stack	*stack_new(int num)
{
	t_stack	*stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->n = num;
	stack->next = NULL;
	return (stack);
}

void		stack_add(t_stack **stack, t_stack *new)
{
	if (*stack && stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
	else if ((!(*stack) || !stack) && new)
		*stack = new;
}

void		stack_delone(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*s;

	if (stack && *stack)
	{
		s = *stack;
		tmp = s;
		s = s->next;
		free(tmp);
	}
}

void		stack_del(t_stack **stack)
{
	t_stack	*lst;
	t_stack	*next;

	lst = *stack;
	while (lst)
	{
		next = lst->next;
		if (lst)
		{
			free(&lst);
			lst = NULL;
		}
		lst = next;
	}
	*stack = NULL;
}