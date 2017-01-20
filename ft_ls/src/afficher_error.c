#include "ft_ls.h"

void	option_invalide(char *option, s_param *param)
{
	ft_printf("ls : option invalide -- '%s'\n", option);
	ft_printf("Saisissez « ls --help » pour plus d'informations.\n");
	free(param);
	exit(0);
}

