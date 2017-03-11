/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strwchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 23:47:16 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 21:51:39 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	get_len_ww(wchar_t *str)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 128)
			len++;
		else if (str[i] < 2048)
			len += 2;
		else if (str[i] < 65536)
			len += 3;
		else if (str[i] < 2097152)
			len += 4;
		i++;
	}
	return (len);
}

void	print_null(int *len)
{
	write(1, "(null))", 6);
	*len += 6;
}

void	loop_function(char *tmp, wchar_t *str, int i, char *s)
{
	while (str[i] != '\0')
	{
		tmp = print_ww(str[i]);
		ft_strcat(s, tmp);
		i++;
		ft_strdel(&tmp);
	}
}

void	print_strwchar(va_list ap, t_info *info, int *len)
{
	wchar_t	*str;
	int		i;
	char	*s;
	char	*tmp;

	tmp = NULL;
	str = va_arg(ap, wchar_t*);
	i = 0;
	s = NULL;
	if (str)
	{
		s = ft_strnew(get_len_ww(str));
		loop_function(tmp, str, i, s);
		tmp = parse_string(info->f_larger, info->att, info->pre, s);
		ft_putstr(tmp);
		*len += ft_strlen(tmp);
	}
	else
		print_null(len);
	ft_strdel(&s);
	ft_strdel(&tmp);
}
