/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:29:24 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 10:41:15 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	uc_dst = (unsigned char*)dst;
	uc_src = (unsigned char*)src;
	if (src >= dst)
		ft_strncpy((char*)uc_dst, (const char*)uc_src, len);
	else
	{
		uc_dst = uc_dst + len - 1;
		uc_src = uc_src + len - 1;
		while (len > 0)
		{
			*uc_dst = *uc_src;
			uc_dst--;
			uc_src--;
			len--;
		}
	}
	return (dst);
}
