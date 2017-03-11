/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:06:07 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 17:10:21 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_c(char *t, t_info *info)
{
	int		i;

	i = 0;
	while (i < info->f_larger)
	{
		ft_putchar(t[i]);
		i++;
	}
}

void	char_config(char *str, t_info *info, int *len)
{
	char	*t;

	t = NULL;
	t = ft_strnew((size_t)info->f_larger);
	if (ft_strchr(info->att, '-') != NULL)
	{
		t[0] = str[0];
		ft_memset((void*)t + 1, ' ', info->f_larger - 1);
	}
	else
	{
		ft_memset((void*)t, ' ', info->f_larger - 1);
		ft_strcat(t, str);
	}
	ft_putstr_c(t, info);
	*len += ft_strlen(t);
	if (info->f_larger > 1 && str[0] == 0)
		*len = *len + 1;
}
