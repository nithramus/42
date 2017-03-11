/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:34:51 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 21:27:06 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*dispatch_parse(char *str, t_info *info, size_t len_init)
{
	if (info->f_larger > (int)len_init && ft_strchr(info->att, '0') != NULL
			&& ft_strchr(info->att, '-') == NULL
			&& ft_strchr(info->att, '#') != NULL
			&& (info->conv == 'x' || info->conv == 'X'))
	{
		str[1] = info->conv	;
		str[ft_strlen(str) - len_init + 1] = '0';
	}
	return (str);
}

char	*parse_spec(char *str, t_info *info)
{
	char	c;

	c = str[0];
	if ((info->conv == 'd' || info->conv == 'o'
				|| info->conv == 'i' || info->conv == 'd'
				|| info->conv == 'u'
				|| info->conv == 'O' || info->conv == 'X'
				|| info->conv == 'x') && ft_strchr(info->att, '#') == NULL
			&& info->pre == 0 && ft_strcmp(str, "0") == 0)
		str[0] = '\0';
	if (info->pre == 0 && ft_strchr(info->att, '#') != NULL && info->conv == 'o'
			&& c == '0')
		str[0] = '0';
	return (str);
}

char	*parse_sq(char *str, t_info *info, int nb_init, size_t len_init)
{
	size_t	len;
	char	*t;

	t = NULL;
	len = ft_strlen(str);
	if (info->pre == 0 && ft_strchr(info->att, '#') != NULL
			&& info->conv == 'x')
		str[0] = '\0';
	if (nb_init < 0 && info->pre > (int)len_init)
	{
		str[ft_strlen(str) - info->pre - 1] = '-';
		str[ft_strlen(str) - len_init] = '0';
	}
	if (info->pre > (int)len_init && nb_init < 0 && str[0] == '0')
	{
		t = ft_strjoin("-", str);
		free(str);
		return (t);
	}
	return (str);
}

char	*parse_sp_plus(t_info *info, char *str)
{
	char	*t;

	t = NULL;
	if (ft_strchr(info->att, '+') != NULL && ft_strchr(str, '-') == NULL)
	{
		t = ft_strjoin("+", str);
		ft_strdel(&str);
		return (t);
	}
	if (ft_strchr(info->att, ' ') != NULL)
	{
		t = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (t);
	}
	return (str);
}

char	*parse_double(char *str, size_t len_init, t_info *info, char *str_ini)
{
	char	*t;

	t = NULL;
	if (info->pre > (int)len_init - 2
			&& (info->conv == 'X' || info->conv == 'x')
			&& ft_strchr(info->att, '#') != NULL
			&& ft_strcmp(str_ini, "0") != 0)
	{
		t = ft_strnew(info->pre + 2);
		t[0] = '0';
		t[1] = info->conv;
		ft_memset(t + 2, '0', info->pre - len_init + 2);
		ft_strcat(t, 1 + ft_strrchr(str, info->conv));
		free(str);
		return (t);
	}
	return (str);
}
