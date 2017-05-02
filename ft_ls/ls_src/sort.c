#include "ft_ls.h"

void	swap_ptr(char **one, char **two)
{
	char *tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

int		sort_ascii(t_mem_stock *mem_ptr)
{
	int j;
	t_mem_stock *tmp;
	char **swap;
	int effect;

	effect = 0;
	tmp = mem_ptr;
	if (!mem_ptr)
		return (0);
	j = 0;
	swap = (char**)&mem_ptr->list_ptr[0];
	while (tmp->list_ptr[j])
	{
		if (ft_strcmp(*swap, tmp->list_ptr[j]) > 0)
		{
			effect = 1;
			swap_ptr(swap, (char**)&tmp->list_ptr[j]);
		}
		swap = (char**)&tmp->list_ptr[j];
		j++;
		if (j == 50 && tmp->next)
		{
			j = 0;
			tmp = tmp->next;
		}
		if (!(tmp->list_ptr[j]) || (j == 50 && !tmp->next))
		{
			if (effect)
			{
				effect = 0;
				swap = (char**)&mem_ptr->list_ptr[0];
				j = 0;
				tmp = mem_ptr;
			}
			else
				break ;
		}
	}
	return (0);
}

static int swap_time(char **a, char **b)
{
	struct stat infoa;
	struct stat infob;

	stat(*a, &infoa);
	stat(*b, &infob);
	if (infoa.st_mtime < infob.st_mtime)
	{
		swap_ptr(a, b);
		return (1);
	}
	return (0);
}


static int		sort_time(t_mem_stock *mem_ptr)
{
	int j;
	t_mem_stock *tmp;
	char **swap;
	int effect;

	effect = 0;
	tmp = mem_ptr;
	j = 0;
	swap = (char**)&mem_ptr->list_ptr[0];
	while (tmp->list_ptr[j])
	{
		if (swap_time(swap, (char**)&tmp->list_ptr[j]))
			effect = 1;
		swap = (char**)&tmp->list_ptr[j];
		j++;
		if (j == 50)
		{
			j = 0;
			tmp = tmp->next;
		}
		if (!(tmp->list_ptr[j]))
		{
			if (effect)
			{
				swap = (char**)&mem_ptr->list_ptr[0];
				j = 0;
				tmp = mem_ptr;
				effect = 0;
			}
		}
	}
	return (0);
}

static int reverse_sort(t_mem_stock *mem_ptr)
{

	return (0);
}

int		ft_sort(t_mem_stock *mem_ptr, t_option option)
{
	if (option.t)
		sort_time(mem_ptr);
	else
		sort_ascii(mem_ptr);

	return (0);
}
