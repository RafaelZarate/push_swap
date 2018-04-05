/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:43:27 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/28 20:03:14 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_b(t_stacks *stacks, int	upper_limit, int lower_limit)
{
	get_current_position(stacks);
	if (stacks->a == NULL || stacks->min_a > upper_limit)
		return ;
	if (stacks->a_first <= upper_limit && stacks->a_first > lower_limit)
		handle_ops("pb", stacks);
	else
		handle_ops("ra", stacks);
	push_to_b(stacks, upper_limit, lower_limit);
}

void	create_solution(t_stacks *stacks, int i, t_sols **solutions, int orientation)
{
	int	a_ops[2];
	int	b_ops[2];
	int	mixed_ops[4];
	int	temp_n;
	t_stack	*tmp;
	int	c_ops;
	int i_a;

	// a_ops = (int *)ft_memalloc(sizeof(int) * 2);
	// b_ops = (int *)ft_memalloc(sizeof(int) * 2);
	// mixed_ops = (int *)ft_memalloc(sizeof(int) * 4);
	b_ops[0] = (orientation == 1) ? 3 : 4;
	b_ops[1] = (orientation == 1) ? i : stacks->length_b - i;
	mixed_ops[2] = 0;
	mixed_ops[3] = 0;
	tmp = stacks->b;
	i++;
	while (--i)
		tmp = tmp->next;
	temp_n = tmp->n;
	tmp = stacks->a;
	i_a = 0;
	while (tmp && tmp->next)
	{
		if (temp_n > tmp->n && temp_n < tmp->next->n)
			break ;
		i_a++;
		tmp = tmp->next;
	}
	get_current_position(stacks);
	a_ops[0] = (i_a <= stacks->length_a / 2) ? 1 : 2;
	a_ops[1] = (a_ops[0] == 1) ? i_a : stacks->length_a - i_a;
	if (a_ops[0] == b_ops[0] - 2)
	{
		mixed_ops[0] = a_ops[0] + 4;
		if (a_ops[1] == b_ops[1])
			mixed_ops[1] = a_ops[1];
		else if (a_ops[1] > b_ops[1])
		{
			mixed_ops[1] = b_ops[1];
			mixed_ops[2] = a_ops[0];
			mixed_ops[3] = a_ops[1] - b_ops[1];
		}
		else if (a_ops[1] < b_ops[1])
		{
			mixed_ops[1] = a_ops[1];
			mixed_ops[2] = b_ops[0];
			mixed_ops[3] = b_ops[1] - a_ops[1];
		}
	}
	else
	{
		mixed_ops[0] = a_ops[0];
		mixed_ops[1] = a_ops[1];
		mixed_ops[2] = b_ops[0];
		mixed_ops[3] = b_ops[1];
	}
	c_ops = mixed_ops[1] + mixed_ops[3];
	solutions_add(solutions, solutions_new(a_ops, b_ops, mixed_ops, c_ops));
}

void	perform_best_solution(t_stacks *stacks, t_sols **solutions)
{
	int		comp;
	int		save;
	t_sols	*tmp;
	int 	i;

	tmp = *solutions;
	i = 0;
	comp = INT_MAX;
	save = 0;
	while (tmp)
	{
		if (tmp->c_ops < comp)
			save = i;
		i++;
		tmp = tmp->next;
	}
	tmp = *solutions;
	ft_putnbr(save);
	save++;
	while (--save)
		tmp = tmp->next;
    
    // ft_putstr("0: ");ft_putnbr(tmp->mixed_ops[0]);ft_putchar('\t');
    // ft_putstr("1: ");ft_putnbr(tmp->mixed_ops[1]);ft_putchar('\t');
    // ft_putstr("2: ");ft_putnbr(tmp->mixed_ops[2]);ft_putchar('\t');
    // ft_putstr("3: ");ft_putnbr(tmp->mixed_ops[3]);ft_putchar('\n');
	while (tmp->mixed_ops[1])
	{
		if (tmp->mixed_ops[0] == 1)
			handle_ops("ra", stacks);
		else if (tmp->mixed_ops[0] == 2)
			handle_ops("rra", stacks);
		else if (tmp->mixed_ops[0] == 3)
			handle_ops("rb", stacks);
		else if (tmp->mixed_ops[0] == 4)
			handle_ops("rrb", stacks);
		else if (tmp->mixed_ops[0] == 5)
			handle_ops("rr", stacks);
		else if (tmp->mixed_ops[0] == 6)
			handle_ops("rrr", stacks);
		tmp->mixed_ops[1]--;
	}
	handle_ops("pa", stacks);
	while (tmp->mixed_ops[3])
	{
		if (tmp->mixed_ops[2] == 1)
			handle_ops("ra", stacks);
		else if (tmp->mixed_ops[2] == 2)
			handle_ops("rra", stacks);
		else if (tmp->mixed_ops[2] == 3)
			handle_ops("rb", stacks);
		else if (tmp->mixed_ops[2] == 4)
			handle_ops("rrb", stacks);
		tmp->mixed_ops[3]--;
	}
	solutions_delete(solutions);
}

void	return_partitions_to_a(t_stacks *stacks)
{
	t_sols	*solutions;
	// t_stack	*a;
	t_stack	*b;
	// int position;
	int i;

	// position = 0;
	while (stacks->length_b != 0)
	{
		i = -1;
		while (++i < stacks->length_b)
		{
			b = stacks->b;
			if (i <= stacks->length_b / 2)
				create_solution(stacks, i, &solutions, 1);
			else
				create_solution(stacks, i, &solutions, 2);
		}

		if (stacks->length_a < 2)
			handle_ops("pa", stacks);
		else
			perform_best_solution(stacks, &solutions);
		print_stacks(stacks);
	}
}