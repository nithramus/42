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

static int	add_dep(f_path **act_path, f_path *path_to_add)
{


f_path	**path_combinaison(f_path **all_path, f_path ***best_path_comb, f_path **act_path, int nb_path, int nb_road)
{
	f_path **new_dep;

	nb_road--;
	ft_putendl("test2");
	while (all_path[nb_path])
	{
		ft_printf("%d\n", nb_road);
		new_dep = f_path_join(act_path, all_path[nb_path]);
		ft_putendl("test1");
		if (nb_road > 0)
			path_combinaison(all_path, best_path_comb, new_dep, nb_path + 1, nb_road);
		else if (nb_road == 0)
		{
			ft_putendl("yolo");
			//testrapidite
			//return (NULL);
		}
		ft_putendl("test1");
		nb_path++;
	}
	return (NULL);
}
