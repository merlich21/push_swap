/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:36:25 by merlich           #+#    #+#             */
/*   Updated: 2022/02/05 17:46:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_finally_sorted(t_stack *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)	
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_is_sorted(t_stack *head)
{
	int	count;

	count = 0;
	while (head->next)
	{
		if (head->value > head->next->value)	
			count++;
		head = head->next;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	ft_find_max(t_stack *head)
{
	int	max;

	if (!head)
		return (0);
	max = head->value;
	while (head->next)
	{
		if (max < head->next->value)
			max = head->next->value;
		head = head->next;
	}
	return (max);
}

int	ft_find_min(t_stack *head)
{
	int	min;

	if (!head)
		return (0);
	min = head->value;
	while (head->next)
	{
		if (min > head->next->value)
			min = head->next->value;
		head = head->next;
	}
	return (min);
}
