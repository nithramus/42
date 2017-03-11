/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:23:08 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/01 20:42:56 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_len_u_arg(unsigned long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (n < 10)
		{
			i++;
			return (i);
		}
		else
		{
			i++;
			n = n / 10;
		}
	}
	return (i);
}

int		ft_get_len_arg(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (n < 10)
		{
			i++;
			return (i);
		}
		else
		{
			i++;
			n = n / 10;
		}
	}
	return (i);
}
