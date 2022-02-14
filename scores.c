/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:48:59 by merlich           #+#    #+#             */
/*   Updated: 2022/02/14 23:49:23 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_scores(t_values *vals, t_stack *elem_b)
{
	int		count;
	t_stack	*bigger;
	t_stack	*res;
	t_stack	*elem_a;

	count = 0;
	bigger = NULL;
	res = NULL;
	elem_a = vals->head_a;
	while (elem_a && count < 2)
	{
		if (elem_a->value > elem_b->value)
		{
			count++;
			ft_push_elem(&bigger, elem_a);
		}
		elem_a = elem_a->next;
	}
	res = ft_find_min(bigger);
	ft_delete_stack(&bigger);
	return (res);
}

void	ft_set_scores(t_values *vals)
{
	t_stack	*res;
	t_stack	*elem_b;

	res = NULL;
	elem_b = vals->head_b;
	while (elem_b)
	{
		res = ft_get_scores(vals, elem_b);
		elem_b->score_a_r = res->score_a_r;
		elem_b->score_a_rr = res->score_a_rr;
		elem_b = elem_b->next;
	}
}
