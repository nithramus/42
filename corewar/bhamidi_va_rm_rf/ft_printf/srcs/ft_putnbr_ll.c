/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:56:05 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/08 18:20:57 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_ll(long long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_ll(nb * -1);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr_ll(nb / 10);
		ft_putnbr_ll(nb % 10);
	}
	else
		ft_putchar(48 + nb);
}
