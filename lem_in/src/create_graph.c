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

int		parse_tubes(g_struct **list_salles, char *line)
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
	ft_putendl("yolo4");
		if (!salle1 || !salle2)
			return (0);
		salle1->liaisons = ptr_join(salle1->liaisons, salle2);
		salle2->liaisons = ptr_join(salle2->liaisons, salle1);
	ft_putendl("yolo5");
		cont = get_next_line(0, &line);
	}
	i = 0;
	while (list_salles[i])
	{
		j = 0;
		while (list_salles[i]->liaisons[j])
		{
			ft_putstr(list_salles[i]->name);
			ft_putendl((list_salles[i])->liaisons[j]->name);
			j++;
		}
		i++;
	}

	return (1);
}

g_struct	**parse_salles(g_struct **list_salles, char *start, char *end)
{
	char *line;
	char **split;

	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
			break;
		if (!(split = ft_strsplit(line, ' ')))
			return (NULL);
		list_salles = graphe_join(list_salles, new_g_struct(split[0]));
	}

	ft_putendl("yolo1");
	parse_tubes(list_salles, line);
	ft_putendl("yolo2");
	return (list_salles);
}

g_struct	**create_graph()
{
	g_struct **list_salles;
	char	*start;
	char	*end;

	list_salles = (g_struct**)malloc(sizeof(g_struct));
	list_salles[0] = NULL;
	list_salles = parse_salles(list_salles, start, end);
	return (list_salles);
}
