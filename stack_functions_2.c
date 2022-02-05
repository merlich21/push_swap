/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:23:49 by merlich           #+#    #+#             */
/*   Updated: 2022/02/03 22:04:05 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stack	*ft_stack_last(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	}
	return (tmp);
}

t_stack	*ft_stack_last_but_one(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (tmp != NULL)
	{
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
	}
	return (tmp);
}
