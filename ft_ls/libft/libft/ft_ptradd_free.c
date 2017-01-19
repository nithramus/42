#include "libft.h"

void	**ft_ptradd(void **list, void *add)
{
	int i;
	void **new;

	i = 0;
	while (list[i])
		i++;
	if (!(new = (void**)malloc(sizeof(void*) * (i + 2))))
		return (NULL);
	i = 0;
	while (list[i])
	{
		new[i] = list[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = NULL;
	free(list);
	return (new);
}
