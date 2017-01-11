/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:36:02 by bandre            #+#    #+#             */
/*   Updated: 2017/01/06 00:02:27 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"lem_in.h"

int		afficher(g_struct **list_salles)
{
	int i = 0;
	int j = 0;


	ft_putendl("###############");
	while (list_salles[i])
	{
		ft_putendl((list_salles[i])->name);
		i++;
	}
	ft_putendl("###############");
}

int		afficher_road(f_path **path)
{
	int i = 0;
	int j = 0;
	ft_putendl("##############################");
	while (path[i])
	{
		afficher(path[i]->path);
		i++;
	}
	ft_putendl("###############################");
}

int		main()
{
	g_struct **graphe;
	f_path		**path;
	g_struct *start;
	g_struct *end;
	f_path		**best_path;
	f_path		*ac_path[1];
	int i;

	ac_path[0] = NULL;
	graphe = create_graph(&start, &end);
	afficher(graphe);
	path = find_path(start, end);
	if (make_dependance(path) == 0)
		return (0);




	i = 0;
	while (path[i])
		i++;
	ft_printf("%d\n", i);
	best_path = NULL;
	path_combinaison(path, &best_path, ac_path, 0, 3, 10);
	ft_putendl("final!");
	afficher_road(best_path);
	return (1);

}
