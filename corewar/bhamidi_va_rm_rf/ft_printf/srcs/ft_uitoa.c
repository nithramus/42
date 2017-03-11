/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:46:48 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 00:20:51 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_size(long long int nb, int base, int *len)
{
	if (nb >= base)
	{
		get_size(nb / base, base, len);
		get_size(nb % base, base, len);
	}
	else
		(*len)++;
}

static void		ft_fill_str(char *str, long long int n, int *index, int base)
{
	if (n >= base)
	{
		ft_fill_str(str, n % base, index, base);
		ft_fill_str(str, n / base, index, base);
	}
	else
	{
		if (n > 9)
		{
			str[*index] = 'a' - 10 + n;
			*index = *index + 1;
		}
		else
		{
			str[*index] = 48 + n;
			*index = *index + 1;
		}
	}
}

char			*ft_uitoa(long long int n, int base)
{
	char	*str;
	int		i;
	int		len;

	if (n < 0)
		n = n * -1;
	len = 0;
	i = 0;
	get_size(n, base, &len);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	ft_fill_str(str, n, &i, base);
	return (ft_strrev(str));
}
