/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:38:27 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 21:18:52 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_arg(t_info *info, va_list ap, int *len)
{
	if (info->conv == 'c' && info->m_longer == NULL)
		print_char(ap, info, len);
	else if ((info->conv == 'c' && info->m_longer != NULL) || info->conv == 'C')
		print_wchar(ap, info, len);
	else if (info->conv == 'd' || info->conv == 'i')
		brute_int(info, ap, len);
	else if (info->conv == 's' && info->m_longer == NULL)
		print_string(ap, info, len);
	else if (info->conv == '%')
		print_percent(info->pre, info->f_larger, info->att, len);
	else if (info->conv == 'S' ||
			(info->conv == 's' && ft_strcmp("l", info->m_longer) == 0))
		print_strwchar(ap, info, len);
	else if (info->conv == 'D')
		print_li(ap, info, len);
	else if (info->conv == 'p')
		print_pointer(info, ap, len);
	else if (info->conv == 'u' || info->conv == 'o' || info->conv == 'X'
			|| info->conv == 'x' || info->conv == 'O' || info->conv == 'U')
		brute_u_int(info, ap, len);
}

void	brute_u_int(t_info *info, va_list ap, int *len)
{
	if (info->conv == 'U')
		print_uu(ap, info, len);
	else if (info->conv == 'O')
		print_uli(ap, info, len);
	else if (info->m_longer == NULL)
		print_ui(ap, info, len);
	else if (ft_strcmp("hh", info->m_longer) == 0)
		print_uc(ap, info, len);
	else if (ft_strcmp("h", info->m_longer) == 0)
		print_usi(ap, info, len);
	else if (ft_strcmp("l", info->m_longer) == 0)
		print_uli(ap, info, len);
	else if (ft_strcmp("ll", info->m_longer) == 0)
		print_ulli(ap, info, len);
	else if (ft_strcmp("j", info->m_longer) == 0)
		print_uint(ap, info, len);
	else if (ft_strcmp("z", info->m_longer) == 0)
		print_size_t(ap, info, len);
}

void	brute_int(t_info *info, va_list ap, int *len)
{
	if (info->conv == 'c' && info->m_longer == NULL)
		print_char(ap, info, len);
	else if (info->m_longer == NULL)
		print_int(ap, info, len);
	else if (ft_strcmp("hh", info->m_longer) == 0)
		print_sc(ap, info, len);
	else if (ft_strcmp("h", info->m_longer) == 0)
		print_si(ap, info, len);
	else if (ft_strcmp("l", info->m_longer) == 0)
		print_li(ap, info, len);
	else if (ft_strcmp("ll", info->m_longer) == 0)
		print_lli(ap, info, len);
	else if (ft_strcmp("j", info->m_longer) == 0)
		print_lli(ap, info, len);
	else if (ft_strcmp("z", info->m_longer) == 0)
		ft_int_parsing(info, ft_itoa(va_arg(ap, size_t)), len);
}
