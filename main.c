/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/12 23:26:05 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static void	ft_print_stack_address(const t_stack *head)
// {
// 	ft_putstr_fd("stack addr >\n", 1);
// 	while (head)
// 	{
// 		printf("%p\n", head);
// 		head = head->next;
// 	}
// }

static void	ft_free_all(t_values *vals)
{
	ft_delete_stack(&vals->head_a);
	ft_delete_stack(&vals->head_t);
	ft_delete_stack(&vals->head_b);
	free(vals);
}

static void	ft_fill_stacks(t_values *vals)
{
	while (vals->head_t)
	{
		if (vals->head_t->value != vals->min->value && \
			vals->head_t->value != vals->med->value && \
			vals->head_t->value != vals->max->value)
		{	
			ft_pb(&vals->head_b, &vals->head_t);
		}
		else
			ft_pa(&vals->head_a, &vals->head_t);
	}
}

static t_stack	*ft_get_scores(t_values *vals, t_stack *elem_b)
{
	int		count;
	t_stack *bigger;
	t_stack *res;
	t_stack	*elem_a;

	count = 0;
	bigger = NULL;
	res = NULL;
	elem_a = vals->head_a;
	// ft_set_index(&elem_a);
	while (elem_a && count < 2)
	{
		if (elem_a->value > elem_b->value)
		{
			count++;
			ft_push_elem(&bigger, elem_a);
		}
		elem_a = elem_a->next;
	}
	res = ft_find_min(bigger);
	return (res);
}

static void	ft_set_scores(t_values *vals)
{
	t_stack	*res;
	t_stack	*elem_b;
	
	res = NULL;
	elem_b = vals->head_b;
	while (elem_b)
	{
		res = ft_get_scores(vals, elem_b);
		elem_b->score_a_r = res->score_a_r;
		elem_b->score_a_rr = res->score_a_rr;
		// printf("*******\ni = %d\nvalue = %d\n score_a_r = %d\n", vals->head_b->index, vals->head_b->value, vals->head_b->score_a_r);
		// printf("&&&&&& i = %d\nvalue = %d\n score_a_r = %d\nscore_a_rr = %d\n score_b_r = %d\n score_b_rr = %d\n",\
		// elem_b->index, elem_b->value, elem_b->score_a_r, elem_b->score_a_rr, elem_b->score_b_r, elem_b->score_b_rr);
		elem_b = elem_b->next;
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_values 	*vals;

	i = 1;

	vals = malloc(sizeof(t_values));
	vals->head_a = NULL;
	vals->head_b = NULL;
	vals->head_t = NULL;
	vals->min = NULL;
	vals->max = NULL;
	vals->med = NULL;
	ft_check_isdigits(argc, argv);
	while (i < argc)
	{
		ft_push(&vals->head_t, ft_atoi(argv[argc - i]));
		i++;
	}
	ft_check_duplicates(&vals->head_t);

	ft_set_index_ra(&vals->head_t);
	
	vals->min = ft_find_min(vals->head_t);
	vals->med = ft_find_med(vals->head_t);
	printf("mediana value = %d\n", vals->med->value);
	vals->max = ft_find_max(vals->head_t);
	ft_print_stack(vals->head_t);


	if (ft_is_finally_sorted(vals->head_t))
	{
		ft_free_all(vals);
		exit(EXIT_SUCCESS);
	}
	// ft_set_index(&vals->head_t);
	if (ft_is_sorted(vals->head_t))
	{
		ft_final_sort(vals);
		ft_print_stack(vals->head_t);
		printf("*********************\n");
		ft_free_all(vals);
		exit(EXIT_SUCCESS);
	}

	ft_fill_stacks(vals);
	// while (vals->head_b)
	// {
	// 	printf("!!!!@%d\n", vals->head_b->score_a_r);
	// 	vals->head_b = vals->head_b->next;
	// }
	/* Рассчёт scores */
	ft_set_index_ra(&vals->head_a);
	ft_set_index_rb(&vals->head_b);
	t_stack *tmp_b;

	// tmp_b = vals->head_a;
	// while (tmp_b)
	// {
	// 	printf("!!!!@%d\n", tmp_b->score_a_rr);
	// 	tmp_b = tmp_b->next;
	// }
	ft_set_scores(vals);
	ft_set_index_rr(&vals->head_b);
	ft_find_scores_sum(&vals->head_b);
		printf("*********************\n");
	tmp_b = vals->head_b;
	while (tmp_b)
	{
		printf("*******\ni = %d\nvalue = %d\n score_a_r = %d\nscore_a_rr = %d\n score_b_r = %d\n score_b_rr = %d\nscore_rr = %d\nscore_rrr = %d\n\
		ra_rr = %d\nrb_rr = %d\nrra_rrr = %d\n \
		rrb_rrr = %d\nra_rrb = %d\nrb_rra = %d\n \
		min_sum = %d\n", \
		tmp_b->index, tmp_b->value, tmp_b->score_a_r, \
		tmp_b->score_a_rr, tmp_b->score_b_r, tmp_b->score_b_rr, tmp_b->score_rr, tmp_b->score_rrr,\
		tmp_b->ra_rr, tmp_b->rb_rr, tmp_b->rra_rrr, tmp_b->rrb_rrr, tmp_b->ra_rrb, tmp_b->rb_rra,\
		tmp_b->min_sum);
		// printf("!!!!@%d\n", tmp_b->score_b_r);
		tmp_b = tmp_b->next;
	}
	// printf("\n");
	// ft_triple_sort(&head_a);
	ft_print_stack(vals->head_a);
	ft_print_stack(vals->head_b);
	ft_free_all(vals);
	return (0);
}
