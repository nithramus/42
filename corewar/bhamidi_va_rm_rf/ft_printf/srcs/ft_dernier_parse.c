/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dernier_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:30:15 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 23:11:34 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse_last1(char *str, t_info *info)
{
	char	*t;

	t = NULL;
	t = ft_strnew((size_t)info->f_larger);
	ft_memset((void*)t, '0', (size_t)info->f_larger - ft_strlen(str));
	ft_strcat(t, str);
	ft_strdel(&str);
	return (t);
}

void	more_parse_last(t_info *info, char *str, int nb_init, size_t len_init)
{
	if (info->f_larger > (int)len_init && ft_strchr(info->att, '0') != NULL
			&& nb_init < 0 && (info->conv == 'd' || info->conv == 'i'))
	{
		str[0] = '-';
		str[ft_strlen(str) - len_init] = '0';
	}
}
