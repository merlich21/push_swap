/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:34:31 by merlich           #+#    #+#             */
/*   Updated: 2022/02/02 22:41:50 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static void	ft_isspace(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n' || \
			str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v')
	{
		*i = *i + 1;
	}
	return ;
}

static void	ft_issign(const char *str, int *i, int *flag_sign)
{
	if (str[*i] == '-')
	{
		*flag_sign = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
	{
		*flag_sign = 1;
		*i = *i + 1;
	}
	if (!ft_isdigit(str[*i]))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return ;
}

static void	ft_iszero(const char *str, int *i)
{
	while (str[*i] == '0')
	{
		*i = *i + 1;
	}
	return ;
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			flag_sign;
	long long	res;

	i = 0;
	j = 0;
	flag_sign = 1;
	res = 0;
	ft_isspace(str, &i);
	ft_issign(str, &i, &flag_sign);
	ft_iszero(str, &i);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_msg();
		j++;
		res = res * 10 + (str[i] - '0');
		i = i + 1;
	}
	if (res * flag_sign > 2147483647 || res * flag_sign < -2147483648)
		ft_error_msg();
	return (res * flag_sign);
}
