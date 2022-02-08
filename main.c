/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/08 23:55:48 by merlich          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int			i;
	t_stack		*head_a;
	t_stack		*head_b;
	t_values 	*vals;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	vals = malloc(sizeof(t_values));
	vals->min = NULL;
	vals->max = NULL;
	vals->med = NULL;
	ft_check_isdigits(argc, argv);
	while (i < argc)
	{
		ft_push(&head_a, ft_atoi(argv[argc - i]));
		i++;
	}
	ft_check_duplicates(&head_a);
	vals->min = ft_find_min(head_a);
	vals->med = ft_find_med(head_a);
	vals->max = ft_find_max(head_a);
	ft_print_stack(head_a);


	// printf("\n max = %d\n", ft_find_max(head_a)->value);
	// printf("\n min = %d\n", ft_find_min(head_a)->value);
	if (ft_is_finally_sorted(head_a))
		return (0);
	if (ft_is_sorted(head_a))
	{
		vals->min->score_a_rr = 1;
		vals->min->score_a_r = 3;
		while (head_a->value > vals->min->value)
		{
			if (vals->min->score_a_r <= vals->min->score_a_rr)
				ft_ra(&head_a);
			else
				ft_rra(&head_a);
		}
		// ft_print_stack(head_a);
		return (0);
	}
	printf("\n");
	ft_triple_sort(&head_a);
	ft_print_stack(head_a);
	return (0);
}
