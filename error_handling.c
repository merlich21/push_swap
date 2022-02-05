/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:31:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/03 00:00:21 by merlich          ###   ########.fr       */
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
	t_stack	**del;
	t_stack	*tmp;
	t_stack	*head_val;

	del = head;
	head_val = *head;
	while (head_val)
	{
		tmp = head_val->next;
		while (tmp)
		{
			if (head_val->value == tmp->value)
			{
				ft_delete_stack(del);
				ft_error_msg();
			}
			tmp = tmp->next;
		}
		head_val = head_val->next;
	}
}
