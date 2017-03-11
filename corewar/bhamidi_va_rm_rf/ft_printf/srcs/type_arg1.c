/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_arg1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:43:53 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 17:23:38 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_li(va_list ap, t_info *info, int *len)
{
	long int	arg;
	char		*str;

	str = NULL;
	arg = va_arg(ap, long int);
	str = ft_itoa(arg);
	ft_int_parsing(info, str, len);
}

void	print_size_t(va_list ap, t_info *info, int *len)
{
	size_t	arg;
	char	*str;

	str = NULL;
	arg = va_arg(ap, size_t);
	str = parse_ui(arg, info);
	ft_int_parsing(info, str, len);
}

void	print_si(va_list ap, t_info *info, int *len)
{
	short int	arg;
	char		*str;

	str = NULL;
	arg = va_arg(ap, int);
	str = ft_itoa((long long int)arg);
	ft_int_parsing(info, str, len);
}

void	print_lli(va_list ap, t_info *info, int *len)
{
	long long int	arg;
	char			*str;

	str = NULL;
	arg = va_arg(ap, long long int);
	str = ft_itoa(arg);
	ft_int_parsing(info, str, len);
}

void	print_sc(va_list ap, t_info *info, int *len)
{
	signed char	arg;
	char		*str;

	str = NULL;
	arg = va_arg(ap, signed int);
	str = ft_itoa((long long int)arg);
	ft_int_parsing(info, str, len);
}
