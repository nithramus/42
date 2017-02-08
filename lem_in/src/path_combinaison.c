/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_combinaison.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:58:06 by bandre            #+#    #+#             */
/*   Updated: 2017/02/06 23:51:02 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	**t_path_join(t_path **act_path, t_path *path_to_add)
{
	t_path	**new;
	int		i;

	i = 0;
	while (act_path[i])
		i++;
	if (!(new = (t_path**)malloc((i + 2) * sizeof(t_path*))))
		afficher_error();
	i = 0;
	while (act_path[i])
	{
		new[i] = act_path[i];
		i++;
	}
	new[i] = path_to_add;
	new[i + 1] = NULL;
	return (new);
}

static int		dep_test(t_path **act_path, t_path *path_to_add)
{
	int road;
	int i;

	i = 0;
	while (act_path[i])
	{
		road = 0;
		while (act_path[i]->dependance[road])
		{
			if (act_path[i]->dependance[road] == path_to_add)
				return (0);
			road++;
		}
		i++;
	}
	return (1);
}

static void		netab(int new[3], int tab[3])
{
	tab[0] = new[0] + 1;
	tab[1] = new[1] - 1;
	tab[2] = new[2];
}

static void		extend(t_path ***best_path_comb, t_path **new_dep)
{
	free(*best_path_comb);
	*best_path_comb = new_dep;
}

void			path_combinaison(t_path **all_path, t_path ***best_path_comb,
		t_path **act_path, int new[3])
{
	t_path	**new_dep;
	int		tab[3];

	netab(new, tab);
	while (all_path[tab[0]])
	{
		if (dep_test(act_path, all_path[tab[0]]))
		{
			new_dep = t_path_join(act_path, all_path[tab[0]]);
			if (tab[1] > 0)
				path_combinaison(all_path, best_path_comb, new_dep, tab);
			else if (tab[1] == 0)
			{
				if (*best_path_comb == NULL)
					*best_path_comb = new_dep;
				else if (test_nbtour(new_dep, tab[2]) <
						test_nbtour(*best_path_comb, tab[2]))
					extend(best_path_comb, new_dep);
				else
					free(new_dep);
			}
		}
		tab[0] += 1;
	}
	free(act_path);
}
