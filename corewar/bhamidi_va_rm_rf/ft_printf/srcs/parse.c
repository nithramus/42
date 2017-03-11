/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:08:34 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 20:01:32 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_config_larger(char *tmp, char *str, int larger)
{
	int		i;

	i = 0;
	while (i < larger - (int)ft_strlen(str))
	{
		tmp[i] = ' ';
		i++;
	}
	while (i < larger)
	{
		tmp[i] = *str;
		i++;
		str++;
	}
	tmp[i] = '\0';
}

void	ft_config_larger1(char *tmp, char *str, int larger)
{
	int		i;

	i = 0;
	while (i < larger)
	{
		if (*str != '\0')
		{
			tmp[i] = *str;
			str++;
		}
		else
			tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
}

char	*ft_fill_champ(char *att, char *str, int larger)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (larger <= len)
		return (ft_strdup(str));
	tmp = NULL;
	tmp = ft_strnew(larger);
	if (ft_strchr(att, '-') != NULL)
		ft_config_larger1(tmp, str, larger);
	else
		ft_config_larger(tmp, str, larger);
	return (tmp);
}

char	*parse_string(int larger, char *att, int pre, char *arg)
{
	char	*str;
	char	*t;

	t = NULL;
	str = NULL;
	if (pre != -1)
	{
		str = ft_strnew(pre);
		ft_strncpy(str, arg, pre);
		t = ft_fill_champ(att, str, larger);
	}
	else
	{
		str = ft_strdup(arg);
		t = ft_fill_champ(att, str, larger);
	}
	ft_strdel(&str);
	return (t);
}
