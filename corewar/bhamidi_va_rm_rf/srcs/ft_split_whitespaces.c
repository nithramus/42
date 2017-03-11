/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <bhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:23:54 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/07 16:48:19 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		ft_word_number(char *str)
{
	int		n;
	int		in_word;

	if (!*str)
		return (0);
	n = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0'
				&& *str != ',')
		{
			if (in_word == 0)
			{
				in_word = 1;
				n++;
			}
		}
		else if (in_word == 1)
			in_word = 0;
		str++;
	}
	return (n);
}

static char		*ft_fill_tab(char *dest, char *str)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t'
			&& str[i] != ',' && str[i] != '\n' && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		ft_size_str(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
				str[i] != '\0' && str[i] != ',')
		{
			i++;
			nb++;
		}
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\0' || str[i] == ',')
			return (nb);
		i++;
	}
	return (nb);
}

void			init_or_incr(int *w, int *i, int op)
{
	if (op == 1)
	{
		*w = 0;
		*i = 0;
	}
	else
	{
		(*w)++;
		(*i)++;
	}
}

char			**ft_split_whitespaces(char *s)
{
	int		w;
	char	**tab;
	int		i;

	init_or_incr(&w, &i, 1);
	tab = (char **)malloc(sizeof(char *) * (ft_word_number(s) + 1));
	while (w < ft_word_number(s))
	{
		while ((s[i] == '\t' || s[i] == '\n'
					|| s[i] == ',' || s[i] == ' ') && (s[i] != '\0'))
			i++;
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ' '
				&& s[i] != '\0' && s[i] != ',')
		{
			tab[w] = (char*)malloc(sizeof(char) * ft_size_str(s + i));
			tab[w] = ft_fill_tab(tab[w], s + i);
			init_or_incr(&w, &i, 0);
		}
		while (s[i] != ' ' && s[i] != ','
				&& s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
			i++;
		i++;
	}
	tab[w] = 0;
	return (tab);
}
