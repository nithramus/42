/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 11:22:05 by selibert          #+#    #+#             */
/*   Updated: 2016/07/27 17:09:35 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "header.h"

int			ft_count_column(char *chaine)
{
	int len;

	len = 0;
	while (chaine[len] != '\n' && chaine[len] != '\0')
	{
		len++;
	}
	return (len);
}

int			ft_count_line(char *chaine)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

char		**ft_put_in_tab(char *chaine, int *ligne, char **tab, int *i)
{
	int j;

	j = 0;
	while (chaine[*i])
	{
		if (chaine[*i] == '\n')
		{
			tab[*ligne][j] = '\0';
			tab[*ligne][j + 1] = '\0';
			j = 0;
			(*i)++;
			(*ligne)++;
			tab[*ligne] = malloc(ft_count_column(&chaine[(*i) + 1]) + 5);
		}
		else
		{
			tab[*ligne][j] = chaine[*i];
			(*i)++;
			j++;
		}
	}
	return (tab);
}

char		**copy_tab(char *chaine)
{
	char	**tab;
	int		i;
	int		j;
	int		ligne;
	int		column_size;

	ligne = 0;
	i = 0;
	j = 0;
	tab = malloc(sizeof(char **) * ft_count_line(chaine) + 5);
	while (chaine[i] != '\n')
		i++;
	i++;
	column_size = ft_count_column(&chaine[i]);
	tab[ligne] = malloc(ft_count_column(&chaine[i]) + 5);
	tab = ft_put_in_tab(chaine, &ligne, tab, &i);
	tab[ligne] = malloc(column_size + 4);
	while (j <= column_size)
	{
		tab[ligne][j] = '\0';
		j++;
	}
	tab[ligne][j] = '\0';
	return (tab);
}
