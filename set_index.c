/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:58:29 by merlich           #+#    #+#             */
/*   Updated: 2022/02/18 22:20:49 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index_ra(t_stack *head_a)
{
	int		i;
	int		stack_size;

	i = 0;
	stack_size = ft_stack_size(head_a);
	while (head_a)
	{
		head_a->index = i;
		head_a->score_a_r = i;
		if (i == 0)
			head_a->score_a_rr = 0;
		else
			head_a->score_a_rr = stack_size - i;
		i++;
		head_a = head_a->next;
	}
}

void	ft_set_index_rb(t_stack *head_b)
{
	int		i;
	int		stack_size;

	i = 0;
	stack_size = ft_stack_size(head_b);
	while (head_b)
	{
		head_b->index = i;
		head_b->score_b_r = i;
		if (i == 0)
			head_b->score_b_rr = 0;
		else
			head_b->score_b_rr = stack_size - i;
		i++;
		head_b = head_b->next;
	}
}

void	ft_set_index_rr(t_stack *head_b)
{
	while (head_b)
	{
		head_b->score_rr = ft_min(head_b->score_a_r, head_b->score_b_r);
		head_b->score_rrr = ft_min(head_b->score_a_rr, head_b->score_b_rr);
		head_b->ra_new = head_b->score_a_r - head_b->score_rr;
		head_b->rb_new = head_b->score_b_r - head_b->score_rr;
		head_b->rra_new = head_b->score_a_rr - head_b->score_rrr;
		head_b->rrb_new = head_b->score_b_rr - head_b->score_rrr;
		head_b = head_b->next;
	}
}

void	ft_find_scores_sum(t_stack *elem)
{
	while (elem)
	{
		elem->ra_rr = elem->ra_new + elem->score_rr;
		elem->rb_rr = elem->rb_new + elem->score_rr;
		elem->rra_rrr = elem->rra_new + elem->score_rrr;
		elem->rrb_rrr = elem->rrb_new + elem->score_rrr;
		elem->ra_rrb = elem->score_a_r + elem->score_b_rr;
		elem->rb_rra = elem->score_b_r + elem->score_a_rr;
		elem->min_sum = ft_min(\
		ft_min(\
		ft_max(elem->ra_rr, elem->rb_rr), \
		ft_max(elem->rra_rrr, elem->rrb_rrr)), \
		ft_min(elem->ra_rrb, elem->rb_rra));
		elem = elem->next;
	}
}
