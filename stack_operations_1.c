/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:25:23 by merlich           #+#    #+#             */
/*   Updated: 2022/02/14 23:26:43 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **head_a)
{
	t_stack	*tmp;
	t_stack	*elem;

	elem = *head_a;
	tmp = elem->next;
	elem->next = tmp->next;
	*head_a = tmp;
	tmp->next = elem;
	*head_a = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **head_b)
{
	t_stack	*tmp;
	t_stack	*elem;

	elem = *head_b;
	tmp = elem->next;
	elem->next = tmp->next;
	*head_b = tmp;
	tmp->next = elem;
	*head_b = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
	write(1, "ss\n", 3);
}

void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_a, ft_pop(head_b));
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **head_b, t_stack **head_a)
{
	ft_push(head_b, ft_pop(head_a));
	write(1, "pb\n", 3);
}
