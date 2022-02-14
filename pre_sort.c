/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:36:25 by merlich           #+#    #+#             */
/*   Updated: 2022/02/14 23:34:38 by merlich          ###   ########.fr       */
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

int	ft_min(int a, int b)
{
	int	res;

	if (a < b)
		res = a;
	else
		res = b;
	return (res);
}

int	ft_max(int a, int b)
{
	int	res;

	if (a > b)
		res = a;
	else
		res = b;
	return (res);
}

int	ft_nonzero_min(int a, int b)
{
	int	res;

	res = 0;
	if (a < b && a != 0)
		res = a;
	else if (b < a && b != 0)
		res = b;
	else
		res = ft_max(a, b);
	return (res);
}
