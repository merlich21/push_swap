/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:07:24 by merlich           #+#    #+#             */
/*   Updated: 2022/02/14 22:00:48 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **head_a)
{
	t_stack	*first;
	t_stack	*last_but_one;
	t_stack	*last;

	first = *head_a;
	last_but_one = ft_stack_last_but_one(first);
	last = last_but_one->next;
	last_but_one->next = NULL;
	last->next = first;
	*head_a = last;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **head_b)
{
	t_stack	*first;
	t_stack	*last_but_one;
	t_stack	*last;

	first = *head_b;
	last_but_one = ft_stack_last_but_one(first);
	last = last_but_one->next;
	last_but_one->next = NULL;
	last->next = first;
	*head_b = last;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
	ft_rra(head_a);
	ft_rrb(head_b);
	write(1, "rrr\n", 4);
}
