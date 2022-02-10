/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:10:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/10 22:01:00 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_sort(t_values *vals)
{
	while (vals->head_t->value > vals->min->value)
	{
		if (vals->min->score_a_r <= vals->min->score_a_rr)
			ft_ra(&vals->head_t);
		else
			ft_rra(&vals->head_t);
	}
}
