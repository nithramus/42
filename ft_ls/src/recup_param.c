#include "ft_ls.h"

static int add_param(s_param **param, char *chaine)
{
	return (1);
}

s_param		*recup_param(char **list_param)
{
	int i;
	s_param *param;

	i = 0;
	param = new_s_param();
	while (list_param[i])
	{
		if (list_param[i][0] == '-')
			add_param(&param, list_param[i]);
		else
		{
			param->list_fichier = (char**)ft_ptradd((void*)param->
					list_fichier, list_param[i]);
		}
		i++;
	}
	return (param);
}
