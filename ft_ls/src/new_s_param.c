#include "ft_ls.h"

s_param		*new_s_param(void)
{
	s_param *new;

	if (!(new = (s_param*)malloc(sizeof(new))))
		afficher_error_malloc();
	new->rmaj = 0;
	new->r = 0;
	new->a = 0;
	new->l = 0;
	new->t = 0;
	if (!(new->list_fichier = (char**)malloc(sizeof(char*))))
		afficher_error_malloc();
	*new->list_fichier = NULL;
	return (new);
}

