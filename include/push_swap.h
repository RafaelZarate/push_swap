/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:18:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/23 00:29:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libft/libft.h"

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct		s_numbers
{
	int					n;
	struct s_numbers	*next;
}					t_stack;

typedef	struct	s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		n_ops;
	int		length_a;
	int		length_b;
	int		a_max;
	int		b_max;
	int		a_min;
	int		b_min;
	float	a_med;
	float	b_med;
}				t_stacks;

/*
**	MAIN FUNCTIONS
*/

void		parser(t_stacks *stacks, char **input, int ac);
void		handle_ops(char *operations, t_stacks *stacks);
void		put_error(int n);
void		solver(t_stacks *stacks);

/*
**	OPERATIONS
*/

void		do_sa(t_stacks *stacks);
void		do_sb(t_stacks *stacks);
void		do_ss(t_stacks *stacks);
void		do_pa(t_stacks *stacks);
void		do_pb(t_stacks *stacks);
void		do_ra(t_stacks *stacks);
void		do_rb(t_stacks *stacks);
void		do_rr(t_stacks *stacks);
void		do_rra(t_stacks *stacks);
void		do_rrb(t_stacks *stacks);
void		do_rrr(t_stacks *stacks);

/*
**	LIST MANIPULATION
*/

t_stack		*stack_new(int num);
void		stack_add(t_stack **stack, t_stack *new);
void		stack_del(t_stack **stack);
void		stack_del(t_stack **stack);

#endif
