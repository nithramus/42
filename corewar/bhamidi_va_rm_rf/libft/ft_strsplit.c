/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:31:28 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/12 18:59:22 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_del(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char		*ft_fill(char *dst, char const *src, char c)
{
	int		i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char		**ft_real_fill(char **tab, int *nb_w, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < *nb_w && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != c)
		{
			tab[i] = (char*)malloc(sizeof(char) * ft_strlen_del(s + j, c));
			tab[i] = ft_fill(tab[i], s + j, c);
			i++;
		}
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_word;
	char	**tab;

	if (s != NULL)
	{
		nb_word = ft_get_nb_word(s, c);
		if (!(tab = (char**)malloc(sizeof(*tab) * nb_word + 1)))
			return (NULL);
		tab = ft_real_fill(tab, &nb_word, s, c);
		tab[nb_word] = 0;
	}
	else
		return (NULL);
	return (tab);
}
