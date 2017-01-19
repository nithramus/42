#include "ft_ls.h"

static int add_param(s_param **param, char *chaine)
{
}

s_param		*recup_param(char **list_param)
{
	int i;
	s_param *param;

	i = 0;
	while (list_param[i])
	{
		if (list_param[i][0] == '-')
			add_param(&param, list_param[i]);

