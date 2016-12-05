/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:45:17 by bandre            #+#    #+#             */
/*   Updated: 2016/12/05 00:11:54 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_gestion_precision(t_param list, char *s)
{
	int		len;
	char	*string_zero;
	char	*moins;

	string_zero = NULL;
	if ((list.specifier == 'i' || list.specifier == 'd'
				|| list.specifier == 'D'
			|| list.specifier == 'o' || list.specifier == 'O' ||
			list.specifier == 'x' || list.specifier == 'X' ||
			list.specifier == 'u' || list.specifier == 'U') && list.precision)
	{
		len = ft_strlen(s);
		moins = ft_strchr(s, '-');
		if (moins)
			list.precision++;
		if (len < list.precision)
		{
			if (!(string_zero = ft_strnew(list.precision - len + 1)))
				return (NULL);
			while (len != list.precision)
			{
				string_zero[list.precision - len - 1] = '0';
				list.precision--;
			}
			s = ft_strjoin(string_zero, s);
			if (moins)
			{
				moins = ft_strchr(s, '-');
				s[0] = '-';
				*moins = '0';
			}
			return (s);
		}
	}
	if (list.specifier == 's' || list.specifier == 'S')
	{
		len = ft_strlen(s);
		if (len > list.precision && list.precision != -1)
			s[list.precision] = '\0';
		return (s);
	}
	return (s);
}
