#include "push_swap.h"

char	*tri_recursif(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *ret;

	afficher(*a_list,*b_list);
	ft_putendl("entre tri");
	if (is_trie(*a_list, *b_list))
		return (ft_strnew(1));
	if (len == len_max)
		return (NULL);
	if (ret = swap_recursif_a(a_list, b_list, len + 1, len_max))
		return (ret);
	if (ret = swap_recursif_b(a_list, b_list, len + 1, len_max))
		return (ret);
	if (ret = push_recursif_a(a_list, b_list, len + 1, len_max))
		return (ret);
	if (ret = push_recursif_b(a_list, b_list, len + 1, len_max))
		return (ret);
/*	if (ret = rotate_recursif_a(a_list, b_list, len + 1, len_max))
		return (ret);
	if (ret = reverse_recursif_a(a_list, b_list, len + 1, len_max))
		return (ret);*/
	ft_putendl("sorti tri");
	return (NULL);
}

int		recursif(t_checker **a_list, t_checker **b_list)
{
	int len_max;
	char *ret;

	len_max = 1;
	while (1)
	{
		ft_putendl("boucle");
		afficher(*a_list, *b_list);
		ret = tri_recursif(a_list, b_list, 0, len_max);
		if (ret)
		{
			ft_printf("%s", ret);
			return (1);
		}
		len_max++;
	}
	return (1);
}
