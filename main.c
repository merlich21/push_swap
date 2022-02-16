/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/16 22:37:01 by merlich          ###   ########.fr       */
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
	// ft_triple_sort(&vals->head_a);
}

static void	ft_sort(t_values *vals)
{
	ft_set_index_ra(vals->head_a);
	ft_set_index_rb(vals->head_b);
	ft_set_scores(vals);  //////////////////////////////////
	ft_set_index_rr(vals->head_b);
	ft_find_scores_sum(vals->head_b);
	vals->minimal = ft_find_min_min_sum(vals->head_b);
	ft_operation_parser(vals);
	// t_stack	*tmp_b;
	// tmp_b = vals->head_b;
	// while (tmp_b)
	// {
	// 	printf("*******\ni = %d\nvalue = %d\n score_a_r = %d\nscore_a_rr = %d\n score_b_r = %d\n score_b_rr = %d\nscore_rr = %d\nscore_rrr = %d\n\
	// 	ra_rr = %d\nrb_rr = %d\nrra_rrr = %d\n \
	// 	rrb_rrr = %d\nra_rrb = %d\nrb_rra = %d\n \
	// 	min_sum = %d\n", \
	// 	tmp_b->index, tmp_b->value, tmp_b->score_a_r, \
	// 	tmp_b->score_a_rr, tmp_b->score_b_r, tmp_b->score_b_rr, tmp_b->score_rr, tmp_b->score_rrr,\
	// 	tmp_b->ra_rr, tmp_b->rb_rr, tmp_b->rra_rrr, tmp_b->rrb_rrr, tmp_b->ra_rrb, tmp_b->rb_rra,\
	// 	tmp_b->min_sum);
	// 	// printf("!!!!@%d\n", tmp_b->score_b_r);
	// 	tmp_b = tmp_b->next;
	// }
	// 	ft_print_stack(vals->head_a);
	// 	ft_print_stack(vals->head_b);
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
	vals->min = ft_find_min(vals->head_a);
	vals->med = ft_find_med(vals->head_a);
	vals->max = ft_find_max(vals->head_a);
	// printf("min = %d\n",vals->min->value);
	// printf("med = %d\n",vals->med->value);
	// printf("max = %d\n",vals->max->value);
	ft_check_is_sorted(vals);
	ft_fill_stacks(vals);
		ft_print_stack(vals->head_a);
		ft_print_stack(vals->head_b);
	ft_triple_sort(&vals->head_a);
		ft_print_stack(vals->head_a);
	while (ft_stack_size(vals->head_b))
	{
		ft_sort(vals);
		ft_print_stack(vals->head_a);
		ft_print_stack(vals->head_b);
	}
	ft_set_index_ra(vals->head_a);
	ft_final_sort(vals);
		ft_print_stack(vals->head_a);
		ft_print_stack(vals->head_b);
	ft_free_all(vals);
	return (0);
}
