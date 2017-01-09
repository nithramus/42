#include "lem_in.h"

f_path	*new_f_path(g_struct **add)
{
	f_path	*new;

	if (!(new = (f_path*)malloc(sizeof(f_path))))
		return (NULL);
	new->dependance = NULL;
	new->path=add;
	return (new);
}
