/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:36:20 by merlich           #+#    #+#             */
/*   Updated: 2022/02/08 23:55:51 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_bubble_sort(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;	
		}
		i++;
	}
}

static void	ft_check_1_2(t_stack **head)
{
	int		first;
	int		second;
	t_stack	*tmp;

	tmp = *head;
	first = tmp->value;
	second = tmp->next->value;
	if (first > second)
		ft_sa(head);
}

static void	ft_check_2_3(t_stack **head)
{
	int		second;
	int		third;
	t_stack	*tmp;

	tmp = *head;
	second = tmp->next->value;
	third = tmp->next->next->value;
	if (second > third)
		ft_rra(head);
}

void	ft_triple_sort(t_stack **head)
{
	ft_check_1_2(head);
	ft_check_2_3(head);
	ft_check_1_2(head);
}
