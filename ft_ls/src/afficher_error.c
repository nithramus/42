#include "ft_ls.h"

void	option_invalide(char *option, s_param *param)
{
	ft_printf("ft_ls : option invalide -- '%s'\n", option);
	ft_printf("Saisissez « ls --help » pour plus d'informations.\n");
	free(param);
	exit(0);
}

void	afficher_error_malloc(void)
{
	ft_putendl("Meeeec, t'as plus de memoire dispo\n");
	exit(0);
}

void	afficher_error_connais_pas(void)
{
	ft_putendl("Franchement je sais pas ce qu'il s'est passé\n");
	exit(0);
}
