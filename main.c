/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/18 19:53:31 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init(t_values *vals)
{
	vals->head_a = NULL;
	vals->head_b = NULL;
	vals->min = NULL;
	vals->max = NULL;
	vals->med = NULL;
	vals->minimal = NULL;
	vals->stack_a_size = 0;
}

static void	ft_max_med_min(t_values *vals)
{
	vals->max = ft_find_max(vals->head_a);
	vals->med = ft_find_med(vals->head_a);
	vals->min = ft_find_min(vals->head_a);
	vals->stack_a_size = ft_stack_size(vals->head_a);
}

int	main(int argc, char **argv)
{
	int			i;
	t_values	*vals;

	i = 1;
	vals = malloc(sizeof(t_values));
	if (NULL == vals)
		return (0);
	ft_init(vals);
	ft_check_isdigits(argc, argv);
	while (i < argc)
	{
		ft_push(&vals->head_a, ft_atoi(argv[argc - i]));
		i++;
	}
	ft_check_duplicates(&vals->head_a);
	ft_set_index_ra(vals->head_a);
	ft_max_med_min(vals);
	ft_check_is_sorted(vals);
	ft_set_index(vals->head_a);
	if (vals->stack_a_size <= 5)
		ft_sort_small_stack(vals);
	else
		ft_radix_sort(vals);
	ft_free_all(vals);
	return (0);
}
