/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:46:48 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 18:29:49 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_size(size_t nb, size_t base, int *len)
{
	if (nb >= base)
	{
		get_size(nb / base, base, len);
		get_size(nb % base, base, len);
	}
	else
		(*len)++;
}

static void		ft_fill_str(char *str, size_t n, int *index, size_t base)
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

char			*ft_itoa_base(size_t n, size_t base)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	get_size(n, base, &len);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	ft_fill_str(str, n, &i, base);
	return (ft_strrev(str));
}
