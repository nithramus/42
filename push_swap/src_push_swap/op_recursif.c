#include "push_swap.h"

char	*push_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *ret;
	char *tmp;
	
	if (!(*b_list))
		return (NULL);
	op_push(b_list, a_list);
	if (ret = tri_recursif(a_list, b_list, len, len_max))
	{
		tmp = ft_strjoin("pa\n", ret);
		free(ret);
		return (tmp);
	}
	op_push(a_list, b_list);
	return (NULL);
}

char	*push_recursif_b(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *ret;
	char *tmp;

	if (!(*a_list))
		return (NULL);
	op_push(a_list, b_list);
	if (ret = tri_recursif(a_list, b_list, len, len_max))
	{
		tmp = ft_strjoin("pb\n", ret);
		free(ret);
		return (tmp);
	}
	ft_putendl("yolo");
	op_push(b_list, a_list);
	return (NULL);
}
