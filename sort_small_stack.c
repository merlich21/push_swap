/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:11:46 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 20:11:19 by merlich          ###   ########.fr       */
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
		{
			ft_pb(&vals->head_b, &vals->head_a);
		}
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
	vals->max = ft_find_max(vals->head_a);
	vals->med = ft_find_med(vals->head_a);
	vals->min = ft_find_min(vals->head_a);
	ft_check_is_sorted(vals);
	ft_fill_stacks(vals);
	ft_triple_sort(&vals->head_a);
	while (vals->head_b)
		ft_sort(vals);
	ft_set_index_ra(vals->head_a);
	ft_final_sort(vals);
}
