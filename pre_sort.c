/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:36:25 by merlich           #+#    #+#             */
/*   Updated: 2022/02/09 23:00:45 by merlich          ###   ########.fr       */
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
	if (head && ft_stack_last(head)->value > head->value)	
			count++;
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

t_stack	*ft_find_max(t_stack *head)
{
	t_stack	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head->next)
	{
		if (max->value < head->next->value)
			max = head->next;
		head = head->next;
	}
	return (max);
}

t_stack	*ft_find_min(t_stack *head)
{
	t_stack	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head->next)
	{
		if (min->value > head->next->value)
			min = head->next;
		head = head->next;
	}
	return (min);
}
