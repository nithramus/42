/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:45:18 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/30 20:26:32 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_hexa_nbr(unsigned int nb)
{
	if (nb > 15)
	{
		ft_put_hexa_nbr(nb / 16);
		ft_put_hexa_nbr(nb % 16);
	}
	else
	{
		if (nb > 9)
			ft_putchar('a' - 10 + nb);
		else
			ft_putchar('0' + nb);
	}
}
