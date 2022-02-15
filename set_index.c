/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:58:29 by merlich           #+#    #+#             */
/*   Updated: 2022/02/15 22:56:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index_ra(t_stack **head_a)
{
	int		i;
	int		stack_size;
	t_stack	*elem;

	i = 0;
	stack_size = ft_stack_size(*head_a);
	elem = *head_a;
	while (elem)
	{
		elem->index = i;
		elem->score_a_r = i;
		if (i == 0)
			elem->score_a_rr = 0;
		else
			elem->score_a_rr = stack_size - i;
		i++;
		elem = elem->next;
	}
}

void	ft_set_index_rb(t_stack **head_b)
{
	int		i;
	int		stack_size;
	t_stack	*elem;

	i = 0;
	stack_size = ft_stack_size(*head_b);
	elem = *head_b;
	while (elem)
	{
		elem->index = i;
		elem->score_b_r = i;
		if (i == 0)
			elem->score_b_rr = 0;
		else
			elem->score_b_rr = stack_size - i;
		i++;
		elem = elem->next;
	}
}

void	ft_set_index_rr(t_stack **head_b)
{
	t_stack	*elem;

	elem = *head_b;
	while (elem)
	{
		elem->score_rr = ft_min(elem->score_a_r, elem->score_b_r);
		elem->score_rrr = ft_min(elem->score_a_rr, elem->score_b_rr);
		elem = elem->next;
	}
}

void	ft_find_scores_sum(t_stack *elem)
{
	while (elem)
	{
		elem->ra_rr = elem->score_a_r + elem->score_rr;
		elem->rb_rr = elem->score_b_r + elem->score_rr;
		elem->rra_rrr = elem->score_a_rr + elem->score_rrr;
		elem->rrb_rrr = elem->score_b_rr + elem->score_rrr;
		elem->ra_rrb = elem->score_a_r + elem->score_b_rr;
		elem->rb_rra = elem->score_b_r + elem->score_a_rr;
		elem->min_sum = ft_nonzero_min(\
		ft_nonzero_min(\
		ft_nonzero_min(elem->ra_rr, elem->rb_rr), elem->ra_rrb), \
		ft_nonzero_min(\
		ft_nonzero_min(elem->rra_rrr, elem->rrb_rrr), elem->rb_rra));
		elem = elem->next;
	}
}
