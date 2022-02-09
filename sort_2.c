/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:10:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/09 22:46:34 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_sort(t_stack **head_a, t_values *vals)
{
	// vals->min->score_a_rr = 0;
	// vals->min->score_a_r = 0;
	t_stack	*tmp;

	tmp = *head_a;
	while (tmp->value > vals->min->value)
	{
		if (vals->min->score_a_r <= vals->min->score_a_rr)
			ft_ra(head_a);
		else
			ft_rra(head_a);
		tmp = *head_a;
	}
}
