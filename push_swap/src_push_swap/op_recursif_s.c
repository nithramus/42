#include "push_swap.h"

char	*swap_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *tmp;
	char *ret;

	op_swap(*a_list);
	if (ret = tri_recursif(a_list, b_list, len, len_max))
	{
		tmp = ft_strjoin("sa\n", ret);
		free(ret);
		return (tmp);
	}
	op_swap(*a_list);
	return (NULL);
}

char	*swap_recursif_b(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *tmp;
	char *ret;

	op_swap(*b_list);
	if (ret = tri_recursif(a_list, b_list, len, len_max))
	{
		tmp = ft_strjoin("sb\n", ret);
		free(ret);
		return (tmp);
	}
	op_swap(*b_list);
	return (NULL);
}

char	*rotate_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *tmp;
	char *ret;

	op_rotate(a_list);
	if (ret = tri_recursif(a_list, b_list, len, len_max))
	{
		tmp = ft_strjoin("sb\n", ret);
		free(ret);
		return (tmp);
	}
	op_reverse_rotate(a_list);
	return (NULL);
}

char	*reverse_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max)
{
	char *tmp;
	char *ret;

	op_reverse_rotate(a_list);
	if (ret = tri_recursif(a_list, b_list, len, len_max))
	{
		tmp = ft_strjoin("sb\n", ret);
		free(ret);
		return (tmp);
	}
	op_rotate(a_list);
	return (NULL);
}
