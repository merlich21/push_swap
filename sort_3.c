/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:39:40 by merlich           #+#    #+#             */
/*   Updated: 2022/02/16 22:19:42 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_rra_rrr(t_values *vals)
{
	while (vals->minimal->rra_new)
	{
		ft_rra(&vals->head_a);
		vals->minimal->rra_new--;
	}
	while (vals->minimal->score_rrr)
	{
		ft_rrr(&vals->head_a, &vals->head_b);
		vals->minimal->score_rrr--;
	}
}

void	ft_action_rrb_rrr(t_values *vals)
{
	while (vals->minimal->rrb_new)
	{
		ft_rrb(&vals->head_b);
		vals->minimal->rrb_new--;
	}
	while (vals->minimal->score_rrr)
	{
		ft_rrr(&vals->head_a, &vals->head_b);
		vals->minimal->score_rrr--;
	}
}

void	ft_action_ra_rrb(t_values *vals)
{
	while (vals->minimal->score_a_r)
	{
		ft_ra(&vals->head_a);
		vals->minimal->score_a_r--;
	}
	while (vals->minimal->score_b_rr)
	{
		ft_rrb(&vals->head_b);
		vals->minimal->score_b_rr--;
	}
}

void	ft_action_rb_rra(t_values *vals)
{
	while (vals->minimal->score_b_r)
	{
		ft_rb(&vals->head_b);
		vals->minimal->score_b_r--;
	}
	while (vals->minimal->score_a_rr)
	{
		ft_rra(&vals->head_a);
		vals->minimal->score_a_rr--;
	}
}
