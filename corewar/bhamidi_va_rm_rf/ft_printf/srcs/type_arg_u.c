/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_arg_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:12:29 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 20:16:31 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_uc(va_list ap, t_info *info, int *len)
{
	unsigned char	arg;
	char			*str;

	arg = (unsigned char)va_arg(ap, unsigned int);
	str = parse_ui((size_t)arg, info);
	ft_int_parsing(info, str, len);
}

void	print_usi(va_list ap, t_info *info, int *len)
{
	char				*str;
	unsigned short int	arg;

	arg = va_arg(ap, int);
	str = parse_ui(arg, info);
	ft_int_parsing(info, str, len);
}

void	print_uint(va_list ap, t_info *info, int *len)
{
	char				*str;

	str = parse_ui((uintmax_t)va_arg(ap, uintmax_t), info);
	ft_int_parsing(info, str, len);
}

void	print_uli(va_list ap, t_info *info, int *len)
{
	unsigned long int	arg;
	char				*str;

	arg = va_arg(ap, unsigned long int);
	str = parse_ui((size_t)arg, info);
	ft_int_parsing(info, str, len);
}

void	print_ulli(va_list ap, t_info *info, int *len)
{
	unsigned long long int	arg;
	char					*str;

	arg = va_arg(ap, unsigned long long int);
	str = parse_ui((size_t)arg, info);
	ft_int_parsing(info, str, len);
}
