/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:11:46 by merlich           #+#    #+#             */
/*   Updated: 2022/02/18 19:30:12 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_stacks(t_values *vals)
{
	while (vals->head_a && ft_stack_size(vals->head_a) != 3)
	{
		if (vals->head_a->value == vals->min->value || \
			vals->head_a->value == vals->med->value || \
			vals->head_a->value == vals->max->value)
		{
			ft_ra(&vals->head_a);
		}
		else
			ft_pb(&vals->head_b, &vals->head_a);
	}
}

static void	ft_sort(t_values *vals)
{
	ft_set_index_ra(vals->head_a);
	ft_set_index_rb(vals->head_b);
	ft_set_scores(vals);
	ft_set_index_rr(vals->head_b);
	ft_find_scores_sum(vals->head_b);
	vals->minimal = ft_find_min_min_sum(vals->head_b);
	ft_operation_parser(vals);
}

void	ft_sort_small_stack(t_values *vals)
{
	if (vals->stack_a_size == 3)
	{
		ft_triple_sort(&vals->head_a);
		return ;
	}
	ft_check_is_sorted(vals);
	ft_fill_stacks(vals);
	ft_triple_sort(&vals->head_a);
	while (ft_stack_size(vals->head_b))
		ft_sort(vals);
	ft_set_index_ra(vals->head_a);
	ft_final_sort(vals);
}
