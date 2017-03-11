/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:25:03 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 17:25:29 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*chaine_dst;
	char	*chaine_src;
	size_t	i;

	chaine_dst = (char*)dst;
	chaine_src = (char*)src;
	i = 0;
	while (i < n && (chaine_src + 1) != NULL)
	{
		chaine_dst[i] = (unsigned char)chaine_src[i];
		i++;
	}
	return (dst);
}
