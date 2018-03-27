/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ll_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:49:48 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/27 01:45:16 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_sols	*solutions_new(int	**a_op, int **b_op, int **mixed_ops, int c_ops)
{
	t_sols	*node;

	node = (t_sols *)ft_memalloc(sizeof(t_sols));
	node->a_op = (int *)ft_memalloc(sizeof(int) * 2);
	node->b_op = (int *)ft_memalloc(sizeof(int) * 2);
	node->mixed_ops = (int *)ft_memalloc(sizeof(int) * 4);
	if (!node)
		return (NULL);
	node->a_op = *a_op;
	node->b_op = *b_op;
	node->mixed_ops = *mixed_ops;
	node->c_ops = c_ops;
	ft_memdel((int *)&a_op);
	ft_memdel((int *)&b_op);
	ft_memdel((void *)&mixed_ops);
	node->next = NULL;
	return (node);
}

void	solutions_add(t_sols	**solutions, t_sols *new)
{
	if (solutions && *solutions)
	{
		new->next = *solutions;
		*solutions = new;
	}
	else if ((!solutions || !(*solutions)) && new)
		*solutions = new;
}

void	solutions_delone(t_sols **solutions)
{
	t_sols *tmp;

	if (solutions && *solutions)
	{
		tmp = *solutions;
		*solutions = (*solutions)->next;
		ft_memdel((t_sols *)&tmp);
	}
}

void	solutions_delete(t_sols **solutions)
{
	while (*solutions)
		solutions_delone(solutions);
}