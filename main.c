/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/15 20:32:42 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(const t_stack *head)
{
	ft_putstr_fd("stack >\n", 1);
	while (head)
	{
		ft_putnbr_fd(head->value, 1);
		ft_putchar_fd('\n', 1);
		head = head->next;
	}
}

static void	ft_init(t_values *vals)
{
	vals->head_a = NULL;
	vals->head_b = NULL;
	vals->min = NULL;
	vals->max = NULL;
	vals->med = NULL;
	vals->minimal = NULL;
}

static void	ft_fill_stacks(t_values *vals)
{
	while (vals->head_a && ft_stack_size(vals->head_a) != 3)
	{
		if (vals->head_a->value == vals->min->value || \
			vals->head_a->value == vals->med->value || \
			vals->head_a->value == vals->max->value)
		{
			ft_ra(&vals->head_a);
		}
		else
		{
			ft_pb(&vals->head_b, &vals->head_a);
		}
	}
	if (!ft_is_sorted(vals->head_a))
		ft_triple_sort(&vals->head_a);
}

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
	ft_set_index_ra(&vals->head_a);
	ft_final_sort(vals);
	ft_free_all(vals);
	return (0);
}
