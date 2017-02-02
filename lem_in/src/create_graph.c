/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:52:00 by bandre            #+#    #+#             */
/*   Updated: 2017/02/02 13:55:19 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		split_not_valid_salle(char **split, int nb_split)
{
	int i;
	int j;

	i = 0;
	if (split[0][0] == '#')
		return (0);
	while (split[i])
		i++;
	if (i != nb_split)
		return (1);
	i = 1;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (j == 0 && ft_strchr("+-", split[i][j]))
				j++;
			else if (ft_isdigit(split[i][j] == 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static g_struct	**parse_tubes(g_struct **list_salles, char *line, char **fichier)
{
	g_struct	*salle1;
	g_struct	*salle2;
	char		**split;
	int			cont;

	cont = 1;
	while (cont)
	{
		if (!(split = ft_strsplit(line, '-')))
			return (NULL);
		if (split_not_valid_salle(split, 2))
			return (list_salles);
		salle1 = graphchr(list_salles, split[0]);
		salle2 = graphchr(list_salles, split[1]);
		if (!salle1 || !salle2)
			return (list_salles);
		if (!(salle1->liaisons = ptr_join(salle1->liaisons, salle2)) ||
			(!(salle2->liaisons = ptr_join(salle2->liaisons, salle1))))
			return (NULL);
		fichier_comp(fichier, line);
		free(line);
		ft_free_split(split);
		cont = get_next_line(0, &line);
	}
	return (list_salles);
}

static int		parse_test(int *start, int *end, char **split, int i)
{
	if (!(ft_strcmp("##start", split[0])))
		*start = i;
	else if (!(ft_strcmp("##end", split[0])))
		*end = i;
	else if (split[0][0] == '#')
		i = i + 1 - 1;
	else
		return (0);
	return (1);
}

static g_struct	**parse_salles(g_struct **list_salles, int *start, int *end,
		char **fichier)
{
	char	*line;
	char	**split;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (!(split = ft_strsplit(line, ' ')) || !(fichier_comp(fichier, line)))
			return (NULL);
		else if (!split[0])
			return (list_salles);
		else if (parse_test(start, end, split, i))
			i = i + 1 - 1;
		else if (ft_strchr(line, '-'))
			break ;
		else if (split_not_valid_salle(split, 3))
			return (list_salles);
		else if ((i = i + 1))
			list_salles = graphe_join(list_salles, new_g_struct(split[0]));
		free(line);
		ft_free_split(split);
	}
	ft_free_split(split);
	return (parse_tubes(list_salles, line, fichier));
}

g_struct		**create_graph(g_struct **start, g_struct **end, char **fichier)
{
	g_struct	**list_salles;
	int			debut;
	int			fin;
	char		*line;

	debut = -1;
	fin = -1;
	if (!(list_salles = (g_struct**)malloc(sizeof(g_struct*))))
		return (NULL);
	*list_salles = NULL;
	list_salles = parse_salles(list_salles, &debut, &fin, fichier);
	if (debut == fin || debut == -1 || fin == -1)
		return (NULL);
	*start = list_salles[debut];
	*end = list_salles[fin];
	if (!(*start) || !(*end))
		return (NULL);
	return (list_salles);
}
