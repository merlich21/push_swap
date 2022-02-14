/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:23:49 by merlich           #+#    #+#             */
/*   Updated: 2022/02/14 23:09:21 by merlich          ###   ########.fr       */
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

void	ft_push_elem(t_stack **head, t_stack *elem)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (NULL == tmp)
		exit(STACK_OVERFLOW);
	*tmp = *elem;
	if (NULL != elem)
	{
		tmp->next = *head;
		*head = tmp;
	}
}

void	ft_free_all(t_values *vals)
{
	ft_delete_stack(&vals->head_a);
	ft_delete_stack(&vals->head_t);
	ft_delete_stack(&vals->head_b);
	free(vals);
}
