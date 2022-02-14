/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/15 00:04:53 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init(t_values *vals)
{
	vals->head_a = NULL;
	vals->head_b = NULL;
	vals->head_t = NULL;
	vals->min = NULL;
	vals->max = NULL;
	vals->med = NULL;
	vals->minimal = NULL;
}
////////////////////////////////////////////////////////////////////
static void	ft_fill_stacks(t_values *vals)
{
	while (vals->head_a)
	{
		ft_set_index_ra(&vals->head_a);
		if (vals->head_a->value != vals->min->value && \
			vals->head_a->value != vals->med->value && \
			vals->head_a->value != vals->max->value)
		{	
			// ft_push(&vals->head_b, ft_pop(&vals->head_a));
			// write(1, "pb\n", 3);
			ft_pb(&vals->head_b, &vals->head_a);
		}
		else
		{
			if (vals->head_a->score_a_r <= vals->head_a->score_a_rr)
				ft_ra(&vals->head_a);
			else
				ft_rra(&vals->head_a);
		}
	}
}
////////////////////////////////////////////////////////////////////
static void	ft_sort(t_values *vals)
{
	ft_set_index_ra(&vals->head_a);
	ft_set_index_rb(&vals->head_b);
	ft_set_scores(vals);
	ft_set_index_rr(&vals->head_b);
	ft_find_scores_sum(&vals->head_b);
	vals->minimal = ft_find_min_min_sum(vals->head_b);
	ft_operation_parser(vals);
}

int	main(int argc, char **argv)
{
	int			i;
	t_values	*vals;

	i = 1;
	vals = malloc(sizeof(t_values));
	ft_init(vals);
	ft_check_isdigits(argc, argv);
	while (i < argc)
	{
		ft_push(&vals->head_a, ft_atoi(argv[argc - i]));
		i++;
	}
	ft_check_duplicates(&vals->head_a);
	ft_set_index_ra(&vals->head_a);
	vals->min = ft_find_min(vals->head_a);
	vals->med = ft_find_med(vals->head_a);
	vals->max = ft_find_max(vals->head_a);
	ft_check_is_sorted(vals);
	ft_fill_stacks(vals);
	while (ft_stack_size(vals->head_b))
		ft_sort(vals);
	ft_free_all(vals);
	return (0);
}
