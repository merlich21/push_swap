/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:30:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 21:03:22 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **head, TYPE value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (NULL == tmp)
		exit(STACK_OVERFLOW);
	tmp->value = value;
	tmp->next = *head;
	*head = tmp;
}

TYPE	ft_pop(t_stack **head)
{
	t_stack	*elem;
	TYPE	value;

	if (NULL == *head)
		exit(STACK_UNDERFLOW);
	elem = *head;
	value = elem->value;
	*head = elem->next;
	free(elem);
	return (value);
}

TYPE	ft_peak(const t_stack *head)
{
	if (NULL == head)
		exit(STACK_UNDERFLOW);
	return (head->value);
}

void	ft_delete_stack(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}
}

void	ft_free_all(t_values *vals)
{
	ft_delete_stack(&vals->head_a);
	ft_delete_stack(&vals->head_b);
	free(vals);
}
