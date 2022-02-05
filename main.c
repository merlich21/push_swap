/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/05 17:53:18 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static void	ft_print_stack_size(t_stack *head)
// {
// 	ft_putstr_fd("stack_size = ", 1);
// 	ft_putnbr_fd(ft_stack_size(head), 1);
// 	ft_putchar_fd('\n', 1);
// }

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*head_a;
	t_stack	*head_b;

	i = 1;
	num = 0;
	head_a = NULL;
	head_b = NULL;
	ft_check_isdigits(argc, argv);
	while (i < argc)
	{
		ft_push(&head_a, ft_atoi(argv[argc - i]));
		i++;
	}
	ft_check_duplicates(&head_a);
	ft_print_stack(head_a);
	// printf("\n Is sorted? > %d\n", ft_is_sorted(head_a));
	// if (ft_is_sorted(head_a))
	// {
	// 	head_a->score_a_r
	// }
	printf("\n max = %d\n", ft_find_max(head_a));
	printf("\n min = %d\n", ft_find_min(head_a));
	if (ft_is_finally_sorted(head_a))
		return (0);


	// printf("%d\n", ft_is_sorted(head_a));

	// ft_swap(&head_a);
	// ft_pb(&head_b, &head_a);
	// ft_reverse_rotate(&head_a);
	// ft_print_stack(head_a);
	// ft_print_stack(head_b);

	// num = ft_stack_last(head)->value;

	

	// ft_putnbr_fd(num, 1);
	// ft_print_stack_size(head);
	// ft_putchar_fd('\n', 1);

	// ft_push(&head, 555);
	// ft_putnbr_fd(ft_peak(head), 1);
	
	// ft_putchar_fd('\n', 1);
	// ft_print_stack(head);
	// ft_print_stack_size(head);

	// ft_delete_stack(&head);
	
	// ft_print_stack(head);
	// ft_print_stack_size(head);

	return (0);
}
