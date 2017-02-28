/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 16:57:31 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/21 16:57:36 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
	{
		if (nb > 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else if (nb < 10)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
}

void	ft_putstr(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		ft_putchar(str[n]);
		n++;
	}
}
