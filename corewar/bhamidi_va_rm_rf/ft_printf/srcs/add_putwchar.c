/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_putwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:55:57 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 22:58:30 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_putwchar(wchar_t w, char *n)
{
	char	*str;
	char	*b;

	str = NULL;
	b = NULL;
	if (w < 2048)
	{
		b = (char*)malloc(17);
		ft_strncpy(b, "110xxxxx 10xxxxxx", 17);
		str = ft_get_char(b, n, 2);
	}
	else if (w < 65536)
	{
		b = (char*)malloc(27);
		ft_strncpy(b, "1110xxxx 10xxxxxx 10xxxxxx", 26);
		str = ft_get_char(b, n, 3);
	}
	else if (w < 2097152)
	{
		b = (char*)malloc(27);
		ft_strncpy(b, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx", 36);
		str = ft_get_char(b, n, 4);
	}
	free(b);
	return (str);
}
