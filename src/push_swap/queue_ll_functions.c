/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ll_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:46:32 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/25 04:06:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:47:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/23 01:09:43 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/push_swap.h"

// t_queue	*queue_new(char **op)
// {
// 	t_queue	*node;

// 	node = (t_queue *)ft_memalloc(sizeof(t_queue));
// 	if (!node)
// 		return (NULL);
// 	node->op = ft_strdup(*op);
// 	ft_strdel(*op);
// 	node->next = NULL;
// 	return (node);
// }

// void	queue_add(t_queue **q, t_queue *new)
// {
// 	t_queue	*queue;
	
// 	if (q && *q && new)
// 	{
// 		queue = *q;
// 		while (queue->next != NULL)
// 			queue = queue->next;
// 		queue->next = new;
// 	}
// }

// void	queue_remove(t_queue **q, t_queue *new)
// {
// 	t_queue *queue;
// 	t_queue	*tmp;

// 	if (q && *q)
// 	{
// 		queue = *q;
// 		tmp = queue;
// 		queue = queue->next;
// 		ft_strdel(tmp->op);
// 		ft_memdel(&tmp);
// 	}
// }

// void	queue_del(t_queue **q, t_queue *new)
// {
// 	t_queue *queue;

// 	if (q && *q)
// 		queue = q;
// 	while(queue)
// 		queue_remove(queue);
// }