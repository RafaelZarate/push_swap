/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:56:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/26 18:39:31 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	put_error(int n)
{
	ft_putstr_fd("Error", 2);
	exit (n);
}

void	handle_ops(char *operations, t_stacks *stacks)
{
	stacks->n_ops += 1;
	if (ft_strcmp(operations, "sa") == 0)
		do_sa(stacks);
	else if (ft_strcmp(operations, "sb") == 0)
		do_sb(stacks);
	else if (ft_strcmp(operations, "pa") == 0)
		do_pa(stacks);
	else if (ft_strcmp(operations, "pb") == 0)
		do_pb(stacks);
	else if (ft_strcmp(operations, "ra") == 0)
		do_ra(stacks);
	else if (ft_strcmp(operations, "rb") == 0)
		do_rb(stacks);
	else if (ft_strcmp(operations, "rra") == 0)
		do_rra(stacks);
	else if (ft_strcmp(operations, "rrb") == 0)
		do_rrb(stacks);
	else if (ft_strcmp(operations, "ss") == 0)
		do_ss(stacks);
	else if (ft_strcmp(operations, "rr") == 0)
		do_rr(stacks);
	else if (ft_strcmp(operations, "rrr") == 0)
		do_rrr(stacks);
	else
		put_error(4);
	// print_stacks(stacks);
}

void	print_stacks(t_stacks *stacks)
{
	ft_putstr("Stack A: ");
	t_stack *a;
	a = stacks->a;
	while (a)
	{
		ft_putnbr(a->n);
		ft_putchar(' ');
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("Stack B: ");
	t_stack *b;
	b = stacks->b;
	while (b)
	{
		ft_putnbr(b->n);
		ft_putchar(' ');
		b = b->next;
	}
	ft_putchar('\n');
}

void	get_min_max(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	stacks->max_a = INT_MIN;
	stacks->min_a = INT_MAX;
	stacks->max_b = INT_MIN;
	stacks->min_b = INT_MAX;
	a = stacks->a;
	b = stacks->b;
	while (a)
	{
		if (a->n > stacks->max_a)
			stacks->max_a = a->n;
		if (a->n < stacks->min_a)
			stacks->min_a = a->n;
		a = a->next;
	}
	while (b)
	{
		if (b->n > stacks->max_b)
			stacks->max_b = b->n;
		if (b->n < stacks->min_b)
			stacks->min_b = b->n;
		b = b->next;
	}
}

int		get_position_of_max(t_stacks *stacks)
{
	int		c;
	t_stack	*b;

	c = 0;
	b = stacks->b;
	while (b)
	{
		c++;
		if (b->n == stacks->max_b)
			return (c);
		b = b->next;
	}
	return (0);
}

void		swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int			*generate_array(t_stack *stack, int length)
{
	int	*a;
	int i;

	i = 0;
	a = (int *)ft_memalloc(sizeof(int) * length);
	while (stack)
	{
		a[i] = stack->n;
		stack = stack->next;
		i++;
	}
	return (a);
}

int		*sort_median(t_stack *stack, int length)
{
	int i;
	int j;
	int	*a;

	i = -1;
	a = generate_array(stack, length);
	while (++i < length -1)
	{
		j = -1;
		while (++j < length - i - 1)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
	return (a);
}

int			get_median_1(t_stack *stack, int length)
{
	int	*a;
	int	n;
	
	if (length == 1)
		return (stack->n);
	a = sort_median(stack, length);
	n = (((length + 1) / 3) - length % 3) - 1;
	free(a);
	return (a[n]);
}

int			get_median_2(t_stack *stack, int length)
{
	int	*a;
	int	n;
	
	if (length == 1)
		return (stack->n);
	a = sort_median(stack, length);
	n = ((((length + 1) / 3) * 2) - length % 3) - 1;
	free(a);
	return (a[n]);
}

// int			get_median(t_stack *stack, int length)
// {
// 	t_stack	*new;
// 	t_stack	*tmp;
// 	t_stack	*h_tmp;
// 	int		c;
// 	int		len;
// 	int		pos;
// 	int		n;

// 	len = length + 1;
// 	c = 0;
// 	tmp = stack;
// 	h_tmp = tmp;
// 	while (--len)
// 	{
// 		stack = h_tmp;
// 		n = INT_MIN;
// 		while (stack)
// 		{
// 			c++;
// 			if (stack->n > n)
// 			{
// 				n = stack->n;
// 				pos = c;
// 			}
// 			stack = stack->next;
// 		}
// 		tmp = h_tmp;
// 		while (--pos)
// 			tmp = tmp->next;
// 		stack_delone(&tmp);
// 		stack_add(&new, stack_new(n));
// 	}
// 	length /= 2;
// 	while (--length > -1)
// 		new = new->next;
// 	if (length % 2 != 0)
// 		return (new->n);
// 	else
// 		return ((new->n + new->next->n) / 2);
// }
