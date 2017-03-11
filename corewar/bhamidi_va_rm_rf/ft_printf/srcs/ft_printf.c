/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:48:34 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 20:57:29 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	clean_info(t_info **info)
{
	ft_strdel(&(*info)->att);
	(*info)->f_larger = -1;
	(*info)->pre = -1;
	ft_strdel(&(*info)->m_longer);
	(*info)->conv = 0;
}

size_t	ft_loop(const char *format, va_list ap, size_t *i, t_info *info)
{
	int		len;

	len = 0;
	while (format[*i] != '\0')
	{
		if (format[*i] == '%')
		{
			*i += fill_info(format + *i + 1, &info);
			print_arg(info, ap, &len);
			clean_info(&info);
		}
		else
		{
			ft_putchar(format[*i]);
			len++;
		}
		(*i)++;
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	t_info		*info;
	size_t		len;

	len = 0;
	i = 0;
	info = NULL;
	info = info_init(info);
	va_start(ap, format);
	len = ft_loop(format, ap, &i, info);
	if (info != NULL)
		free(info);
	va_end(ap);
	return (len);
}
