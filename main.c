/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/09 23:55:31 by merlich          ###   ########.fr       */
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

void	ft_free_all(t_stack **head_a, t_stack **head_b, t_values *vals)
{
	ft_delete_stack(head_a);
	ft_delete_stack(head_b);
	free(vals);
}

void	ft_fill_stack_b(t_stack **head_a, t_stack **head_b, t_values *vals)
{
	t_stack *elem_a;

	elem_a = *head_a;
	printf("\n max = %d\n", vals->max->value);
	// printf("\n med = %d\n", vals->med->value);
	// printf("\n min = %d\n", vals->min->value);
	while (elem_a)
	{
		// if (elem_a->value == vals->min->value)
		
		ft_pb(head_b, head_a);
		// elem_a = elem_a->next;
	}
	ft_print_stack(*head_a);
}

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
	// printf("\n med = %d\n", ft_find_med(head_a)->value);
	// printf("\n min = %d\n", ft_find_min(head_a)->value);
	if (ft_is_finally_sorted(head_a))
	{
		ft_free_all(&head_a, &head_b, vals);
		return (0);
	}
	ft_set_index(&head_a);
	if (ft_is_sorted(head_a))
	{
		ft_final_sort(&head_a, vals);
		ft_print_stack(head_a);
		printf("*********************\n");
		ft_free_all(&head_a, &head_b, vals);
		return (0);
	}
	/* Разбиение стека а */
	ft_fill_stack_b(&head_a, &head_b, vals);
	/* Рассчёт scores */

	// printf("\n");
	// ft_triple_sort(&head_a);
	// ft_print_stack(head_a);
	// ft_print_stack(head_b);
	ft_free_all(&head_a, &head_b, vals);
	return (0);
}
