/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:31:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/17 21:54:35 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_msg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_isdigits(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		ft_atoi(argv[i]);
		i++;
	}
}

void	ft_check_duplicates(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*elem;

	elem = *head;
	while (elem)
	{
		tmp = elem->next;
		while (tmp)
		{
			if (elem->value == tmp->value)
			{
				ft_delete_stack(head);
				ft_error_msg();
			}
			tmp = tmp->next;
		}
		elem = elem->next;
	}
}
