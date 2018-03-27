/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:18:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/27 02:40:19 by rzarate          ###   ########.fr       */
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

typedef	struct		s_sols
{
	int				*a_op;
	int				*b_op;
	int				*mixed_ops;
	int				c_ops;
	struct	s_sols	*next;
}					t_sols;

typedef struct		s_queue
{
	int				op;
	struct s_queue	*next;
}					t_queue;

typedef	struct	s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_queue	*q;
	int		n_ops;
	int		length_a;
	int		length_b;
	int		max_a;
	int		max_b;
	int		max_b_pos;
	int		min_a;
	int		min_b;
	int		partition_1_length;
	int		partition_2_length;
	int		partition_3_length;
	int		a_first;
	int		a_second;
	int		a_last;
	int		b_first;
	int		b_second;
	int		b_last;
}				t_stacks;

/*
**	MACROS
*/

# define TRUE  1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*
**	MAIN FUNCTIONS
*/

void		parser(t_stacks *stacks, char **input, int ac);
void		handle_ops(char *operations, t_stacks *stacks);
void		put_error(int n);
void		print_stacks(t_stacks *stacks);

/*
**	SOLVER
*/

void		solver(t_stacks *stacks);
void		get_current_position(t_stacks *stacks);
void		get_min_max(t_stacks *stacks);
int			get_position_of_max(t_stacks *stacks);
int			check_if_sorted(t_stack *stack);
int			check_if_rev_sorted(t_stacks *stacks);
void		sort_a_1(t_stacks *stacks, char **a_op);
void		sort_b_1(t_stacks *stacks, char **b_op);
void		return_to_a_1(t_stacks *stacks);

void		algorithm_2(t_stacks *stacks);
int			get_median_1(t_stack *stack, int length, t_stacks **stacks);
int			get_median_2(t_stack *stack, int length, t_stacks **stacks);


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
void		stack_delone(t_stack **stack);
void		stack_del(t_stack **stack);
t_queue		*queue_new(char **op);;
void		queue_add(t_queue **q, t_queue *new);
void		queue_add(t_queue **q, t_queue *new);
void		queue_add(t_queue **q, t_queue *new);

#endif
