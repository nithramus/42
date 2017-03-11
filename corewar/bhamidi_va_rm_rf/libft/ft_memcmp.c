/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:28:28 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 10:05:43 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	size_t			i;

	i = 0;
	uc_s1 = (unsigned char*)s1;
	uc_s2 = (unsigned char*)s2;
	while (i < n && *uc_s1 == *uc_s2)
	{
		uc_s1++;
		uc_s2++;
		n--;
	}
	if (n == i)
		return (0);
	else
		return (*uc_s1 - *uc_s2);
}
