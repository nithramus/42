#include "ft_ls.h"

void	free_s_param(s_param *param)
{
	free(param->list_fichier);
	free(param);
}
