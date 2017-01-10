#include "lem_in.h"

static int calc_len_road(f_path *path)
{
	int i;

	i = 0;
	while (path->path[i])
		i++;
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
	nb_tour = 1;
	while (fourmis_arrive < nb_fourmis)
	{
		len_road = calc_len_road(list_road[nb_road]);
		while (list_road[nb_road])
		{
			if (nb_tour > len_road)
				fourmis_arrive++;
			nb_road++;
		}
		nb_tour++;
	}
	return (nb_tour);
}


