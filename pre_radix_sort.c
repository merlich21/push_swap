/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_radix_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:04:35 by merlich           #+#    #+#             */
/*   Updated: 2022/02/18 18:46:51 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dec_to_bin(int dec)
{
	int	k;
	int	bin;

	k = 1;
	bin = 0;
	while (dec)
	{
		bin += (dec % 2) * k;
		k *= 10;
		dec /= 2;
	}
	return (bin);
}

void	ft_set_index(t_stack *head)
{
	int		*tab;
	int		len;
	int		i;

	if (!head)
		return ;
	len = ft_stack_size(head);
	tab = malloc(sizeof(int) * ft_stack_size(head));
	ft_fill_tab(tab, head);
	ft_bubble_sort(tab, len);
	while (head)
	{
		i = 0;
		while (i < len)
		{
			if (head->value == tab[i])
			{
				head->dec_index = i;
				break ;
			}
			i++;
		}
		head = head->next;
	}
	free(tab);
}
