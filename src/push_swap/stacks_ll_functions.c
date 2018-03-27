/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_ll_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/26 12:21:44 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	stack_add(t_stack **stack, t_stack *new)
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

	if (stack && *stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	stack_del(t_stack **stack)
{
	while (*stack)
		stack_delone(stack);
	*stack = NULL;
}