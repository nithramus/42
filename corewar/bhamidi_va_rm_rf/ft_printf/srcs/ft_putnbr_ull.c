/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:56:05 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/04 22:51:40 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_ull(size_t nb)
{
	if (nb >= 10)
	{
		ft_putnbr_ull(nb / 10);
		ft_putnbr_ull(nb % 10);
	}
	else
		ft_putchar(48 + nb);
}
