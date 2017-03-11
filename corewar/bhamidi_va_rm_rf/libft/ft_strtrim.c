/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:37:41 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/15 09:50:49 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_trim_end(char *str, size_t len)
{
	while (str[len] == ' ' || str[len] == '\t'
			|| str[len] == '\n' || str[len] == '\0')
	{
		str[len] = '\0';
		len = len - 1;
	}
	return (str);
}

static	char	*ft_trim_begin(char const *s, char *new)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while (s[i] != '\0' && s[i])
	{
		new[cpt] = s[i];
		cpt++;
		i++;
	}
	new[cpt] = '\0';
	return (new);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	char	*new_2;
	size_t	len;

	new_2 = NULL;
	if (s != NULL)
	{
		len = ft_strlen(s);
		if ((!(new = (char*)malloc(sizeof(char) * len + 1))) || s == NULL)
			return (NULL);
		new = ft_trim_begin(s, new);
		new = ft_trim_end(new, ft_strlen(new));
		if (!(new_2 = (char*)malloc(sizeof(char) * ft_strlen(new) + 1)))
			return (NULL);
		ft_strcpy(new_2, new);
	}
	return (new_2);
}
