/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:10:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/18 22:20:46 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_sort(t_values *vals)
{
	while (vals->head_a->value > vals->min->value)
	{
		if (vals->min->score_a_r <= vals->min->score_a_rr)
			ft_ra(&vals->head_a);
		else
			ft_rra(&vals->head_a);
	}
}

void	ft_check_is_sorted(t_values *vals)
{
	if (ft_is_finally_sorted(vals->head_a))
	{
		ft_free_all(vals);
		exit(EXIT_SUCCESS);
	}
	if (ft_is_sorted(vals->head_a))
	{
		ft_final_sort(vals);
		ft_free_all(vals);
		exit(EXIT_SUCCESS);
	}
}

void	ft_action_ra_rr(t_values *vals)
{
	while (vals->minimal->ra_new)
	{
		ft_ra(&vals->head_a);
		vals->minimal->ra_new--;
	}
	while (vals->minimal->score_rr)
	{
		ft_rr(&vals->head_a, &vals->head_b);
		vals->minimal->score_a_rr--;
	}
}

void	ft_action_rb_rr(t_values *vals)
{
	while (vals->minimal->rb_new)
	{
		ft_rb(&vals->head_b);
		vals->minimal->rb_new--;
	}
	while (vals->minimal->score_rr)
	{
		ft_rr(&vals->head_a, &vals->head_b);
		vals->minimal->score_rr--;
	}
}

void	ft_operation_parser(t_values *vals)
{
	if (vals->minimal->min_sum == vals->minimal->rra_rrr)
		ft_action_rra_rrr(vals);
	else if (vals->minimal->min_sum == vals->minimal->rrb_rrr)
		ft_action_rrb_rrr(vals);
	else if (vals->minimal->min_sum == vals->minimal->ra_rrb)
		ft_action_ra_rrb(vals);
	else if (vals->minimal->min_sum == vals->minimal->rb_rra)
		ft_action_rb_rra(vals);
	else if (vals->minimal->min_sum == vals->minimal->ra_rr)
		ft_action_ra_rr(vals);
	else if (vals->minimal->min_sum == vals->minimal->rb_rr)
		ft_action_rb_rr(vals);
	ft_pa(&vals->head_a, &vals->head_b);
}
