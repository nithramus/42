/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:36:02 by bandre            #+#    #+#             */
/*   Updated: 2017/02/02 18:26:28 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		search_solution(f_path **a_path, int tab[3], f_path ***best)
{
	f_path	**ac_path;

	*best = NULL;
	ac_path = (f_path**)malloc(sizeof(f_path*));
	*ac_path = NULL;
	path_combinaison(a_path, best, ac_path, tab[0], tab[1], tab[2]);
}

static f_path	**best_path_comb(f_path **a_path, int nbfoumis)
{
	f_path	**best_path;
	f_path	**new_best;
	int		tab[3];

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = nbfoumis;
	search_solution(a_path, tab, &new_best);
	if (!(new_best))
		afficher_error();
	best_path = new_best;
	tab[1] = 2;
	while (new_best)
	{
		search_solution(a_path, tab, &new_best);
		if (new_best)
		{
			free(best_path);
			best_path = new_best;
		}
		tab[1]++;
	}
	fourmis_chemins(best_path, nbfoumis);
	free(best_path);
	return (best_path);
}

int				main(void)
{
	g_struct	**graphe;
	f_path		**path;
	g_struct	*start_end[2];
	int			nbfourmis;
	char		*fichier;

	if (ft_is_number(&nbfourmis, &fichier) == 0)
		afficher_error();
	graphe = create_graph(&start_end[0], &start_end[1], &fichier);
	if (!(graphe))
		afficher_error();
	if (!(path = find_path(start_end[0], start_end[1])))
		afficher_error_path(path, graphe, fichier);
	if (path[0] == NULL)
		afficher_error_path(path, graphe, fichier);
	ft_putendl(fichier);
	free(fichier);
	if (make_dependance(path) == 0)
		return (0);
	best_path_comb(path, nbfourmis);
	ft_free_list_g_struct(graphe);
	ft_free_list_f_path(path);
	return (1);
}
