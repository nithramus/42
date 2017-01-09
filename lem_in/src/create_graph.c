/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:52:00 by bandre            #+#    #+#             */
/*   Updated: 2017/01/05 13:34:41 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		parse_tubes(g_struct **list_salles, char *line)
{
	g_struct *salle1;
	g_struct *salle2;
	char **split;
	int cont;
	int i;
	int j;

	cont = 1;
	split = NULL;
	while (cont)
	{
	ft_putendl("yolo3");
		split = ft_strsplit(line, '-');
		salle1 = graphchr(list_salles, split[0]);
		salle2 = graphchr(list_salles, split[1]);
		if (!salle1 || !salle2)
			return (0);
		salle1->liaisons = ptr_join(salle1->liaisons, salle2);
		salle2->liaisons = ptr_join(salle2->liaisons, salle1);
	ft_putendl("yolo5");
		cont = get_next_line(0, &line);
	}
	i = 0;

	return (1);
}


int		static split_not_valid_salle(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	if (i != 1)
		return (1);
	return (0);
}

static g_struct	**parse_salles(g_struct **list_salles, int *start, int *end)
{
	char *line;
	char **split;
	int i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
			break;
		if (!(split = ft_strsplit(line, ' ')))
			return (NULL);
		if (split_not_valid_salle(split))
			return (list_salles);
		if (!(ft_strcmp("##start", split[0])))
			*start = i;
		else if (!(ft_strcmp("##end", split[0])))
			*end = i;
		else
		{
			list_salles = graphe_join(list_salles, new_g_struct(split[0]));
			i++;
		}
		free(line);
	}
	i = 0;
	while (list_salles[i])
	{
		ft_putendl(list_salles[i]->name);
		i++;
	}
	parse_tubes(list_salles, line);
	return (list_salles);
}

g_struct	**create_graph(g_struct **start, g_struct **end)
{
	g_struct	**list_salles;
	int			debut;
	int			fin;

	list_salles = (g_struct**)malloc(sizeof(g_struct*));
	list_salles[0] = NULL;
	list_salles = parse_salles(list_salles, &debut, &fin);
	*start = list_salles[debut];
	*end = list_salles[fin];
	return (list_salles);
}
