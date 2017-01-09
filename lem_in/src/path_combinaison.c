#include "lem_in.h"

f_path	**path_combinaison(f_path **a_path, f_path ***best_path_comb, int nb_path, int nb_road)
{
	int place;

	place = nb_road - nb_path - 1;
	while (a_path[nb_path])
	{
		//add_dependance à best_path_comb
		if (place > 0)
			path_combinaison(a_path, best_path_comb, nb_path + 1, nb_path + place);
		else if (place == 0)
		{
			ft_putendl("yolo");
			//testrapidite
			return (NULL);
		}
		nb_path++;
	}
	return (NULL);
}
