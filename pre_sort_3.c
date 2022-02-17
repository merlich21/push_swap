/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:24:13 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 19:52:40 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min_min_sum(t_stack *head)
{
	t_stack	*min;

	min = head;
	while (head)
	{
		if (min->min_sum > head->min_sum)
			min = head;
		head = head->next;
	}
	return (min);
}
