/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 08:52:07 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/04 18:29:15 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		i;
	int		is_neg;

	i = 0;
	result = 0;
	is_neg = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (is_neg == -1)
		result = result * -1;
	return (result);
}

int		ft_atoi_bin(const char *str)
{
	int		result;
	int		i;
	int		p;

	i = 0;
	p = 1;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			result = result + p;
		i++;
		p = p * 2;
	}
	return (result);
}
