/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:38:04 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 20:19:01 by merlich          ###   ########.fr       */
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
	ft_set_index(vals->head_a);
	ft_set_index_ra(vals->head_a);
	if (ft_stack_size(vals->head_a) <= 5)
		ft_sort_small_stack(vals);
	else
		ft_radix_sort(vals);
	ft_print_stack(vals->head_a);
	// ft_print_stack(vals->head_b);
	ft_free_all(vals);
	return (0);
}
