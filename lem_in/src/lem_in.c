/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:36:02 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 21:01:19 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	f_path **best_path_comb(f_path **a_path, int nbfoumis)
{
	f_path	**best_path;
	f_path	**ac_path;
	f_path	**new_best;
	int		i;

	i = 1;
	ac_path = (f_path**)malloc(sizeof(f_path*));
	*ac_path = NULL;
	new_best = NULL;
	ft_putendl("test2");
	path_combinaison(a_path, &new_best, ac_path, 0, i, 10);
	ft_putendl("test1");
	if (!(new_best))
		afficher_error();
	best_path = new_best;
	i = 2;
	while (new_best)
	{
		ac_path = (f_path**)malloc(sizeof(f_path*));
		*ac_path = NULL;
		new_best = NULL;
		ft_putendl("tour");
		path_combinaison(a_path, &new_best, ac_path, 0, i, nbfoumis);
		if (new_best)
		{
			free(best_path);
			best_path = new_best;
		}
		i++;
	}
	ft_putendl("final!");
	afficher_road(best_path);
	fourmis_chemins(best_path, nbfoumis);
	free(best_path);
	return (best_path);
}

int		main(void)
{
	g_struct	**graphe;
	f_path		**path;
	g_struct	*start;
	g_struct	*end;

	graphe = create_graph(&start, &end);
	if (!(graphe))
		afficher_error();
	afficher(graphe);
	if (!(path = find_path(start, end)))
		afficher_error();
	if (path[0] == NULL)
		afficher_error();
	if (make_dependance(path) == 0)
		return (0);
	best_path_comb(path, 10);
	ft_free_list_g_struct(graphe);
	ft_putendl("sortie");
	ft_free_list_f_path(path);
	ft_putendl("fin");
	while (1);

	return (1);
}
