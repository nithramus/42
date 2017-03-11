/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:36:36 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 23:13:16 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse_last(t_info *info, char *str)
{
	char	*t;

	t = NULL;
	if (ft_strchr(info->att, '0') != NULL && ft_strchr(info->att, '-') == NULL
			&& info->pre == -1 && info->f_larger > (int)ft_strlen(str))
		return (parse_last1(str, info));
	else if (ft_strchr(info->att, '-') != NULL
			&& (size_t)info->f_larger > ft_strlen(str))
	{
		t = ft_strnew((size_t)info->f_larger);
		ft_strncpy(t, str, ft_strlen(str));
		ft_memset((void*)t + ft_strlen(str), ' ',
				(size_t)info->f_larger - ft_strlen(str));
		ft_strdel(&str);
		return (t);
	}
	else if (info->f_larger > (int)ft_strlen(str))
	{
		t = ft_strnew((size_t)info->f_larger);
		ft_memset((void*)t, ' ', info->f_larger - (int)ft_strlen(str));
		ft_strcat(t, str);
		ft_strdel(&str);
		return (t);
	}
	return (str);
}

char	*parse_spec_signe(char *str, t_info *info, size_t len_init, int nb_init)
{
	char	*t;

	t = NULL;
	more_parse_last(info, str, nb_init, len_init);
	if ((info->conv == 'i' || info->conv == 'd')
			&& ft_strchr(info->att, '+') != NULL
			&& info->f_larger > (int)len_init + 1
			&& ft_strchr(info->att, '-') == NULL
			&& ft_strchr(info->att, '0') != NULL && nb_init > 0)
	{
		str[0] = '+';
		str[ft_strlen(str) - len_init - 1] = '0';
	}
	if (nb_init < 0 && info->pre > (int)len_init && (info->conv == 'i'
				|| info->conv == 'd') && ft_strchr(info->att, '-') == NULL
			&& info->f_larger == -1)
	{
		str[info->pre - (int)len_init] = '0';
		t = ft_strjoin("-", str);
		free(str);
		return (t);
	}
	return (str);
}

char	*the_parsing(char *str, t_info *info, size_t len_init, int nb_init)
{
	if (ft_strchr(info->att, '+') != NULL && info->f_larger > (int)len_init
			&& ft_strchr(info->att, '-') == NULL
			&& ft_strchr(info->att, '0') != NULL && nb_init >= 0)
	{
		str[0] = '+';
		str[ft_strlen(str) - len_init - 1] = '0';
	}
	if (ft_strchr(info->att, '0') != NULL && info->f_larger > (int)len_init
			&& ft_strchr(info->att, '-') == NULL && nb_init >= 0
			&& ft_strchr(info->att, '+') == NULL
			&& ft_strchr(info->att, ' ') != NULL)
	{
		str[0] = ' ';
		str[ft_strlen(str) - len_init - 1] = '0';
	}
	if (ft_strchr(info->att, '0') != NULL && info->f_larger > (int)len_init
			&& ft_strchr(info->att, '-') == NULL && nb_init >= 0
			&& ft_strchr(info->att, '+') != NULL &&
			ft_strchr(info->att, ' ') == NULL
			&& (info->conv == 'd' || info->conv == 'i'))
		str[0] = '+';
	return (str);
}

char	*parse_pre(t_info *info, char *str)
{
	char	*t;

	t = NULL;
	if (info->pre > (int)ft_strlen(str))
	{
		t = ft_strnew((size_t)info->pre);
		ft_memset((void*)t, '0', info->pre - (int)ft_strlen(str));
		ft_strcat(t, str);
		ft_strdel(&str);
		return (t);
	}
	return (str);
}

void	ft_int_parsing(t_info *info, char *str, int *len)
{
	size_t	len_init;
	int		nb_init;
	char	*str_ini;

	str_ini = ft_strdup(str);
	nb_init = ft_atoi(str);
	len_init = ft_strlen(str);
	str = parse_spec(str, info);
	str = parse_pre(info, str);
	if ((info->conv == 'd' || info->conv == 'i') && nb_init >= 0)
		str = parse_sp_plus(info, str);
	str = parse_last(info, str);
	str = dispatch_parse(str, info, len_init);
	str = parse_spec_signe(str, info, len_init, nb_init);
	str = the_parsing(str, info, len_init, nb_init);
	str = parse_sq(str, info, nb_init, len_init);
	str = parse_double(str, len_init, info, str_ini);
	ft_putstr(str);
	*len += ft_strlen(str);
	free(str_ini);
	free(str);
}
