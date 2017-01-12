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

void	afficher_error(void)
{
	ft_putendl("ERROR");
	exit(0);
}


