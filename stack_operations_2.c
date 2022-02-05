/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:05:33 by merlich           #+#    #+#             */
/*   Updated: 2022/02/05 18:07:21 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **head_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *head_a;
	second = first->next;
	last = ft_stack_last(first);
	first->next = NULL;
	last->next = first;
	*head_a = second;
	write(1, "ra\n", 2);
}

void	ft_rb(t_stack **head_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *head_b;
	second = first->next;
	last = ft_stack_last(first);
	first->next = NULL;
	last->next = first;
	*head_b = second;
	write(1, "rb\n", 2);
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	write(1, "rr\n", 2);
}
