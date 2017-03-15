/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:07:45 by bandre            #+#    #+#             */
/*   Updated: 2016/12/04 22:40:48 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_gestion_attrib_moins(t_param list, char *s)
{
	int		len;
	char	*string_zero;
	char	*ptr;

	len = ft_strlen(s);
	if (len < list.width)
	{
		if (!(string_zero = ft_strnew(list.width - len + 1)))
			return (NULL);
		if (list.minus)
		{
			while (len != list.width)
			{
				string_zero[list.width - len - 1] = ' ';
				list.width--;
			}
			s = ft_strjoin(s, string_zero);
		}
		else if (list.use_zero && list.precision <= 0)
		{
			while (len != list.width)
			{
				string_zero[list.width - len - 1] = '0';
				list.width--;
			}
			s = ft_strjoin(string_zero, s);
			if (list.diese && list.specifier == 'x')
			{
				ptr = ft_strchr(s, 'x');
				*ptr = '0';
				s[1] = 'x';
			}
			ptr = ft_strchr(s, '-');
			if (ptr)
			{
				s[0] = '-';
				*ptr = '0';
			}
			ptr = ft_strchr(s, '+');
			if (ptr != NULL)
			{
				s[0] = '+';
				*ptr = '0';
			}
		}
		else
		{
			while (len != list.width)
			{
				string_zero[list.width - len - 1] = ' ';
				list.width--;
			}
			s = ft_strjoin(string_zero, s);
		}
	}
	return (s);
}

char	*ft_gestion_attrib_plus(t_param list, char *s)
{
	char chain_zero[2];

	chain_zero[1] = '\0';
	if (list.plus && ft_strchr("idD", list.specifier))
	{
		if (s[0] != '-')
		{
			chain_zero[0] = '+';
			s = ft_strjoin(chain_zero, s);
		}
	}
	else if (list.space && s[0] != '-' && ft_strchr("idD", list.specifier))
	{
		chain_zero[0] = ' ';
		s = ft_strjoin(chain_zero, s);
	}
	return (s);
}

char	*ft_gestion_attrib_diese(t_param list, char *s)
{
	char chain[3];

	if (!list.diese)
		return (s);
	if (ft_strchr("xX", list.specifier) && s[0] == '0')
		return (s);
	if ((list.specifier == 'x' || list.specifier == 'X') && s[0] != '\0')
	{
		chain[0] = '0';
		chain[1] = list.specifier;
		chain[2] = '\0';
		s = ft_strjoin(chain, s);
	}
	else if ((list.specifier == 'o' || list.specifier == 'O') && s[0] != '0')
	{
		chain[0] = '0';
		chain[1] = '\0';
		s = ft_strjoin(chain, s);
	}
	else if (list.specifier == 'p')
	{
		chain[0] = '0';
		chain[1] = 'x';
		chain[2] = '\0';
		s = ft_strjoin(chain, s);
	}
	return (s);
}
