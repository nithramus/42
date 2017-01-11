#include "lem_in.h"

static f_path	**f_path_join(f_path **act_path, f_path *path_to_add)
{
	f_path	**new;
	int i;

	i = 0;
	while (act_path[i])
		i++;
	if (!(new = (f_path**)malloc((i + 2) * sizeof(f_path*))))
		return (NULL);
	i  = 0;
	while (act_path[i])
	{
		new[i] = act_path[i];
		i++;
	}
	new[i] = path_to_add;
	new[i + 1] = NULL;
	return (new);
}

static int	dep_test(f_path **act_path, f_path *path_to_add)
{
	int road;
	int i;

	i = 0;
	while (act_path[i])
	{
		road = 0;
		while (act_path[i]->dependance[road])
		{
			ft_printf("dep:");
			if (act_path[i]->dependance[road] == path_to_add)
				return (0);
			road++;
		}
		i++;
	}
	return (1);
}

f_path	**path_combinaison(f_path **all_path, f_path ***best_path_comb, f_path **act_path, int nb_path, int nb_road, int nb_fourmis)
{
	f_path **new_dep;

	nb_road--;
	//ft_putendl("test2");
	while (all_path[nb_path])
	{
		//ft_printf("%d\n", nb_road);
		if (dep_test(act_path, all_path[nb_path]))
		{
			new_dep = f_path_join(act_path, all_path[nb_path]);
			//ft_putendl("test1");
			if (nb_road > 0)
				path_combinaison(all_path, best_path_comb, new_dep, nb_path + 1, nb_road, nb_fourmis);
			else if (nb_road == 0)
			{
				ft_putendl("yolo");
				afficher_road(new_dep);
				ft_printf("nb-tours: %d\n", test_nbtour(new_dep, nb_fourmis));
				if (*best_path_comb == NULL)
					*best_path_comb = new_dep;
				else if (test_nbtour(new_dep, 10) < test_nbtour(*best_path_comb, nb_fourmis))
					*best_path_comb = new_dep;
				//return (NULL);
			}
		}
		//ft_putendl("test3");
		nb_path++;
	}
	return (NULL);
}
