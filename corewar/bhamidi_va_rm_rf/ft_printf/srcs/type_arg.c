/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:45:55 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 20:12:38 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_int(va_list ap, t_info *info, int *len)
{
	int		arg;
	char	*str;

	arg = va_arg(ap, int);
	str = ft_itoa((long long int)arg);
	ft_int_parsing(info, str, len);
}

void	print_pointer(t_info *info, va_list ap, int *len)
{
	void	*ptr;
	char	*str;
	char	*t;
	char	*b;

	b = NULL;
	t = NULL;
	ptr = va_arg(ap, void*);
	str = NULL;
	str = ft_itoa_base((size_t)ptr, 16);
	b = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strjoin("0x", b);
	if (info->f_larger == -1)
		ft_more_pointer(str, len);
	else
	{
		t = ft_fill_champ(info->att, str, info->f_larger);
		ft_putstr(t);
		*len += ft_strlen(t);
		if (info->f_larger > (int)ft_strlen(t))
			ft_strdel(&t);
	}
	ft_strdel(&str);
	ft_strdel(&b);
}

void	print_string(va_list ap, t_info *info, int *len)
{
	char	*arg;
	char	*str;

	str = NULL;
	arg = va_arg(ap, char*);
	if (!arg)
	{
		ft_putstr("(null)");
		*len += 6;
	}
	else if (info->pre == -1 && info->f_larger == -1 && info->att == NULL)
	{
		ft_putstr(arg);
		*len += ft_strlen(arg);
	}
	else
	{
		str = parse_string(info->f_larger, info->att, info->pre, arg);
		*len = *len + ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
	}
}

void	print_percent(int pre, int f_larger, char *att, int *len)
{
	char	*str;

	str = NULL;
	if (pre == -1 && f_larger == -1 && !att)
	{
		ft_putchar('%');
		*len = *len + 1;
	}
	else
	{
		str = ft_fill_champ(att, "%", f_larger);
		ft_putstr(str);
		*len += ft_strlen(str);
		if (ft_strlen(str) > 1)
			ft_strdel(&str);
	}
}

void	print_char(va_list ap, t_info *info, int *len)
{
	char	t[2];

	t[0] = va_arg(ap, int);
	t[1] = '\0';
	if (info->f_larger < 2)
	{
		ft_putchar(t[0]);
		*len = *len + 1;
	}
	else
		char_config(t, info, len);
}
