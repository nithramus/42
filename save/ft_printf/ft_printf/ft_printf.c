/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:14:32 by bandre            #+#    #+#             */
/*   Updated: 2016/12/04 17:23:46 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *line, ...)
{
	va_list		ap;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(ap, line);
	while (line[i])
	{
		if (line[i] != '%')
		{
			ft_putchar(line[i]);
			i++;
			len++;
		}
		else
			len += ft_gestionspe(line, &i, ap);
	}
	va_end(ap);
	return (len);
}
