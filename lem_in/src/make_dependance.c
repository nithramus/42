#include "lem_in.h"

static int dep_find(f_path *path, f_path *path2)
{
	int i;
	f_path **new;

	i = 1;
	while (path->dependance[i])
		i++;
	if (!(new = (f_path**)malloc(i * sizeof(f_path*))))
		return (0);
	i = 0;
	while (path->dependance[i])
	{
		new[i] = path->dependance[i];
		i++;
	}
	new[i] = path2;
	new[i] = NULL;
	ft_putendl("dep trouvé");
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
		k = 1;
		while (list_path[i]->path[k])
		{
			m = 1;
			while (list_path[u]->path[m])
			{
				if (!(list_path[u]->path[m + 1]))
					break;
				if (list_path[i]->path[k] == list_path[u]->path[m])
					return (dep_find(list_path[i], list_path[u])+
							dep_find(list_path[u], list_path[i]));
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
		if ((add_dependance(list_path, i) == 0))
			return (0);
		i++;
	}
	ft_putendl("finyolo");
	return (1);
}
