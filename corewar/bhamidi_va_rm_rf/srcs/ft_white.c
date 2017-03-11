/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_white.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:35:33 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/07 17:06:00 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		init_v(int *i, int *s, int *c)
{
	*i = 0;
	*c = 0;
	*s = 0;
}

static int		ft_nb_words(char *str)
{
	int i;
	int sym;
	int count;

	init_v(&i, &sym, &count);
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != ',' && str[i] != '\t' &&
				str[i] != ' ' && str[i] != '\n' && str[i])
		{
			i++;
			sym = 1;
		}
		if (str[i] == ',' || str[i] == '\t'
				|| str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count);
}

static int		ft_ln_w(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] != '\t' && str[i] != ' '
			&& str[i] != '\n' && str[i] && str[i] != ',')
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_white(char *str)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	res = malloc(sizeof(char*) * (ft_nb_words(str) + 1));
	while (str[i])
	{
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
					|| str[i] == ',') && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			res[j] = malloc(sizeof(char) * ft_ln_w(str, i) + 1);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != ','
					&& str[i] != '\n' && str[i])
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
