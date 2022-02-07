/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:36:20 by merlich           #+#    #+#             */
/*   Updated: 2022/02/07 23:43:15 by merlich          ###   ########.fr       */
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

void	ft_bubble_sort(int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i;
		while (tab[j + 1])
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j]);
				j++;
			}
			else
				break ;
		}
		i++;
	}
}

// void	ft_triple_sort(t_stack *head)
// {
    
// }