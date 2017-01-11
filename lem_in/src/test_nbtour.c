#include "lem_in.h"

static int calc_len_road(f_path *path)
{
	int i;

	i = 0;
	while (path->path[i])
		i++;
	i--;
	return (i);
}

int		test_nbtour(f_path **list_road, int nb_fourmis)
{
	int nb_road;
	int len_road;
	int fourmis_arrive;
	int nb_tour;

	fourmis_arrive = 0;
	nb_road = 0;
	len_road = 0;
	nb_tour = 0;
	while (fourmis_arrive <= nb_fourmis)
	{
		nb_road = 0;
		while (list_road[nb_road])
		{
			len_road = calc_len_road(list_road[nb_road]);
			//ft_printf("lenroad:%d\n", len_road);
			if (nb_tour >= len_road)
				fourmis_arrive++;
			//ft_printf("foumi:%d\n", fourmis_arrive);
			nb_road++;
		}
		nb_tour++;
		//ft_printf("nb_tours1: %d\n", nb_tour);
	}
	nb_tour--;
	return (nb_tour);
}
