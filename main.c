/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/07 23:43:02 by merlich          ###   ########.fr       */
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
	int		i;
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*min;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	min = NULL;
	ft_check_isdigits(argc, argv);
	while (i < argc)
	{
		ft_push(&head_a, ft_atoi(argv[argc - i]));
		i++;
	}
	ft_check_duplicates(&head_a);
	min = ft_find_min(head_a);
	ft_print_stack(head_a);


	// printf("\n max = %d\n", ft_find_max(head_a)->value);
	// printf("\n min = %d\n", ft_find_min(head_a)->value);
	// if (ft_is_finally_sorted(head_a))
	// 	return (0);
	// if (ft_is_sorted(head_a))
	// {
	// 	min->score_a_rr = 1;
	// 	min->score_a_r = 3;
	// 	while (head_a->value > min->value)
	// 	{
	// 		if (min->score_a_r <= min->score_a_rr)
	// 			ft_ra(&head_a);
	// 		else
	// 			ft_rra(&head_a);
	// 	}
	// 	ft_print_stack(head_a);
	// 	return (0);
	// }
	int	tab[] = {7, 6, 2, 4, 3, 5, 1};

	ft_bubble_sort(tab);
	i = 0;
	while (i < 7)
	{
		printf("\n%d\n", tab[i]);
		i++;
	}
	return (0);
}
