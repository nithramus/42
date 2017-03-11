/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:41:27 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 16:26:37 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_lx(t_info *info, size_t arg)
{
	char	*t;
	char	*tmp;
	int		i;

	i = 0;
	t = NULL;
	tmp = NULL;
	t = ft_itoa_base(arg, 16);
	if (ft_strcmp("0", t) == 0)
		return (t);
	while (t[i] != '\0')
	{
		t[i] = ft_toupper(t[i]);
		i++;
	}
	if (ft_strchr(info->att, '#') != NULL)
	{
		tmp = ft_strjoin("0X", t);
		ft_strdel(&t);
		return (tmp);
	}
	return (t);
}

char	*get_x(t_info *info, size_t arg)
{
	char	*t;
	char	*tmp;
	int		i;

	i = 0;
	t = NULL;
	tmp = NULL;
	t = ft_itoa_base(arg, 16);
	if (ft_strcmp("0", t) == 0)
		return (t);
	if (ft_strchr(info->att, '#') != NULL)
	{
		tmp = ft_strjoin("0x", t);
		ft_strdel(&t);
		return (tmp);
	}
	return (t);
}

char	*get_octal(t_info *info, size_t arg)
{
	char	*t;
	char	*tmp;

	t = NULL;
	tmp = NULL;
	t = ft_itoa_base(arg, 8);
	if (ft_strchr(info->att, '#') != NULL && t[0] != '0')
	{
		tmp = ft_strjoin("0", t);
		ft_strdel(&t);
		return (tmp);
	}
	return (t);
}

char	*parse_ui(size_t arg, t_info *info)
{
	char	*t;

	t = NULL;
	if (info->conv == 'X')
		t = get_lx(info, arg);
	else if (info->conv == 'x')
		t = get_x(info, arg);
	else if (info->conv == 'o' || info->conv == 'O')
		t = get_octal(info, arg);
	else
		t = ft_itoa_base(arg, 10);
	return (t);
}
