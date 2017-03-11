/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:11:12 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 21:09:07 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_more_pointer(char *str, int *len)
{
	ft_putstr(str);
	*len += ft_strlen(str);
}

void	print_uu(va_list ap, t_info *info, int *len)
{
	char			*str;

	str = parse_ui((size_t)va_arg(ap, unsigned long int), info);
	ft_int_parsing(info, str, len);
}

void	print_ui(va_list ap, t_info *info, int *len)
{
	char			*str;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	str = parse_ui((size_t)arg, info);
	ft_int_parsing(info, str, len);
}
