/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:13:44 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/09 22:47:25 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		str_len;
	char	a;

	str_len = (int)ft_strlen(str);
	i = 0;
	a = c;
	while (str_len >= i)
	{
		if (a == str[str_len])
			return ((char*)str + str_len);
		str_len = str_len - 1;
	}
	return (NULL);
}
