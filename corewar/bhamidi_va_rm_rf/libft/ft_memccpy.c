/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:59:12 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 14:42:46 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*c_dst;
	char	*c_src;

	c_dst = (char*)dst;
	c_src = (char*)src;
	while (n > 0 && *c_src != c)
	{
		*c_dst = *c_src;
		n--;
		c_dst = c_dst + 1;
		c_src = c_src + 1;
	}
	if (n > 0)
	{
		*c_dst = *c_src;
		c_dst = c_dst + 1;
		c_src = c_src + 1;
		return ((void*)c_dst);
	}
	else
		return (NULL);
}
