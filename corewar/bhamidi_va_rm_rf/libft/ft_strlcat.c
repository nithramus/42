/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:02:35 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/07 16:29:01 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	if (size == ft_strlen(dst) + 1)
		return (ft_strlen(dst) + ft_strlen(src));
	else
	{
		dst_len = ft_strlen(dst);
		src_len = ft_strlen(src);
		ft_strncat(dst, src, (size - dst_len - 1));
		return (dst_len + src_len);
	}
}
