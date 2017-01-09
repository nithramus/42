#include "lem_in.h"

static int dep_find(f_path *path)
{
	return (1);
}

static int add_dependance(f_path **list_path, int i)
{
	int u;
	int j;
	int k;
	int m;

	u = i;
	while (list_path[u])
	{
		u++;
		if (!(list_path[u]))
			return (1);
		k = 0;
		while (list_path[i]->path[k])
		{
			m = 0;
			while (list_path[u]->path[m])
			{
				if (list_path[i]->path[k] == list_path[u]->path[m])
					return (dep_find(list_path[i]));
				m++;
			}
			k++;
		}
	}
	return (1);
}

int		make_dependance(f_path **list_path)
{
	int i;

	i = 0;
	ft_putendl("newyolo");
	while (list_path[i])
	{
		ft_printf("boucle 1:i:%d\n", i);
		if ((add_dependance(list_path, i) == 0))
			return (0);
		i++;
	}
	ft_putendl("finyolo");
	return (1);
}
