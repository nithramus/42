#include "ft_ls.h"

t_file	*sort_time(t_file *first)
{
	t_file *tmp;
	int action;
	char *swap_ptr;
	t_file *previous;
	t_file *yolo;

	action = 1;
	if (!first)
		return (NULL);
	while (action)
	{
		action = 0;
		tmp = first;
		previous = NULL;
		while (tmp->next)
		{
			if (tmp->info.st_mtime < tmp->next->info.st_mtime)
			{
				action = 1;
				if (previous)
				{
					yolo = tmp->next->next;
					previous->next = tmp->next;
					tmp->next->next = tmp;
					tmp->next = yolo;
				}
				else
				{
					yolo = tmp->next->next;
					first = tmp->next;
					first->next = tmp;
					tmp->next = yolo;
				}
			}
			previous = tmp;
			if (tmp->next)
				tmp = tmp->next;
		}
	}
	return (first);
}

t_file	*sort_ascii(t_file *first)
{
	t_file *tmp;
	int action;
	char *swap_ptr;
	t_file *previous;
	t_file *yolo;
	int i;

	i = 0;
	action = 1;
	if (!first)
		return (NULL);
	while (action)
	{
		action = 0;
		tmp = first;
		previous = NULL;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->file, tmp->next->file) > 0)
			{
				action = 1;
				if (previous)
				{
					yolo = tmp->next->next;
					previous->next = tmp->next;
					tmp->next->next = tmp;
					tmp->next = yolo;
				}
				else
				{
					yolo = tmp->next->next;
					first = tmp->next;
					first->next = tmp;
					tmp->next = yolo;
				}
			}
			previous = tmp;
			if (tmp->next)
				tmp = tmp->next;
			i++;
		}
	}
	ft_printf("%d\n", i);
	return (first);
}

int		ft_sort(t_file **first, t_option option)
{
	if (option.t)
		*first = sort_time(*first);
	else
		*first =sort_ascii(*first);

	return (0);
}
