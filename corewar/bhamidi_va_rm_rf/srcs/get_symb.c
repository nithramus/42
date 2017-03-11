/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:20:31 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/02 18:05:08 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_param1(char *str)
{
	int		i;

	i = 0;
	if (str[1] == '0')
		return (1);
	while (str[++i] != '\0')
		if (!ft_isdigit(str[i]))
			return (1);
	if (str[0] == 'r' && (ft_atoi(str + 1) >= 1
				&& ft_atoi(str + 1) <= REG_NUMBER))
		return (0);
	return (1);
}

int		is_param2(char *str)
{
	int		i;

	i = 0;
	if (str[0] == LABEL_CHAR && ft_strlen(str) > 1)
	{
		while (str[++i] != '\0')
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (1);
		return (0);
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

int		is_param3(char *str)
{
	if (str[0] != DIRECT_CHAR || ft_strlen(str) < 2)
		return (1);
	return (is_param2(str + 1));
}

int		is_label(char *str)
{
	if (get_occurs(str, ':') != 1)
		return (1);
	if (str[ft_strlen(str) - 1] != LABEL_CHAR)
		return (1);
	while (*str != '\0' && *str != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, *str))
			return (1);
		str++;
	}
	return (0);
}
