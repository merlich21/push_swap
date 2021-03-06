/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:33:19 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 18:22:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_tab(int *tab, t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		tab[i] = head->value;
		i++;
		head = head->next;
	}
}

static t_stack	*ft_get_mediana(int mediana, t_stack *head)
{
	while (head)
	{
		if (head->value == mediana)
			break ;
		head = head->next;
	}
	return (head);
}

t_stack	*ft_find_med(t_stack *head)
{
	t_stack	*med;
	int		*tab;
	int		mediana;
	int		len;

	if (!head)
		return (NULL);
	med = NULL;
	len = ft_stack_size(head);
	tab = malloc(sizeof(int) * ft_stack_size(head));
	ft_fill_tab(tab, head);
	ft_bubble_sort(tab, len);
	mediana = tab[len / 2];
	med = ft_get_mediana(mediana, head);
	free(tab);
	return (med);
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
