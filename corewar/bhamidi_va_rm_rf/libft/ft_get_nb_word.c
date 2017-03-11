/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:40:29 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/12 18:54:40 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_nb_word(char const *s, char c)
{
	int		in_word;
	int		nb_word;
	size_t	i;

	i = 0;
	in_word = 0;
	nb_word = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && in_word == 1)
			in_word = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && in_word == 0 && s[i] != '\0')
		{
			in_word = 1;
			nb_word++;
		}
		while (s[i] != c)
			i++;
	}
	return (nb_word);
}
