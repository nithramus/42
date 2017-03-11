/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:14:04 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 23:04:00 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_fil(char *b, char *n)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (b[i] != '\0')
	{
		if (b[i] == 'x' && n[y])
		{
			b[i] = n[y];
			y++;
		}
		else if (b[i] == 'x')
			b[i] = '0';
		i++;
	}
	return (b);
}

char	*ft_get_char(char *b, char *n, int l)
{
	char	*s;
	int		i;
	char	t[4];
	char	*str;
	char	*tmp;

	str = ft_strnew(4);
	t[0] = 0;
	t[1] = 9;
	t[2] = 18;
	t[3] = 27;
	i = 0;
	s = NULL;
	while (i < l)
	{
		b = ft_fil(ft_strrev(b), ft_strrev(n));
		b = ft_strrev(b);
		s = ft_strsub(b, t[i], 8);
		str[i] = ft_atoi_bin(ft_strrev(s));
		i++;
		free(s);
	}
	tmp = str;
	return (tmp);
}

char	*ft_putwchar(wchar_t w)
{
	char	*n;
	char	*str;

	n = NULL;
	str = NULL;
	n = ft_itoa_base((long int)w, 2);
	str = add_putwchar(w, n);
	free(n);
	return (str);
}

char	*print_ww(wchar_t arg)
{
	char	*str;

	str = NULL;
	if (arg < 128)
	{
		str = ft_strnew(1);
		str[0] = arg;
	}
	else
		str = ft_putwchar(arg);
	return (str);
}

void	print_wchar(va_list ap, t_info *info, int *len)
{
	wchar_t	arg;
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	arg = va_arg(ap, wchar_t);
	tmp = print_ww(arg);
	if (tmp != NULL)
	{
		if (*tmp == 0)
		{
			ft_putchar('\0');
			(*len)++;
		}
		else
		{
			str = parse_string(info->f_larger, info->att, info->pre, tmp);
			*len += ft_strlen(str);
			ft_putstr(str);
		}
	}
	ft_strdel(&tmp);
	ft_strdel(&str);
}
