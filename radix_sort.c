/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:40:30 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 21:01:03 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_values *vals)
{
	int	i;
	int	j;
	int	stack_a_size;
	int	max_bits;
	int max_index;

	i = 0;
	j = 0;
	stack_a_size = ft_stack_size(vals->head_a);
	max_index = stack_a_size - 1;
	max_bits = 0;
	while (max_index >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a_size)
		{
			if ((vals->head_a->dec_index >> i) & 1)
				ft_ra(&vals->head_a);
			else
				ft_pb(&vals->head_b, &vals->head_a);
			j++;
		}
		while (vals->head_b)
			ft_pa(&vals->head_a, &vals->head_b);
		i++;
	}
}
