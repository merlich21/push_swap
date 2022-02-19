/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:47:48 by merlich           #+#    #+#             */
/*   Updated: 2022/02/19 10:58:31 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pop_elem(t_stack **head)
{
	t_stack	*elem;

	if (NULL == *head)
		exit(STACK_UNDERFLOW);
	elem = *head;
	*head = elem->next;
	return (elem);
}

void	ft_push_elem(t_stack **head, t_stack *elem)
{
	if (NULL != elem)
	{
		elem->next = *head;
		*head = elem;
	}
}

void	ft_push_copy(t_stack **head, t_stack *elem)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (NULL == tmp)
		exit(STACK_OVERFLOW);
	*tmp = *elem;
	tmp->next = *head;
	*head = tmp;
}
