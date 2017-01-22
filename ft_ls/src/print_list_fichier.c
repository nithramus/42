#include "ft_ls.h"

void	print_list_fichier(char *path, s_param *param)
{
	char **list;
	int i;

	i = 0;
	list = tab_of_dir(path, param);
	while (list[i])
	{
		if (list[i][0] == '.')
		{
			if (param->a)
				ft_printf("%s\n", list[i]);
		}
		else
			ft_printf("%s\n", list[i]);
		i++;
	}
}
