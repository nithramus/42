#include "ft_ls.h"

int	sort_time(t_file *first)
{
	t_file *tmp;
	int action;
	char *swap_ptr;
	t_file *previous;
	t_file *yolo;

	action = 1;
	if (!tmp)
		return (0);
	while (action)
	{
		action = 0;
		tmp = first;
		previous = NULL;
		while (tmp->next)
		{
			if (tmp->info.st_mtime > tmp->next->info.st_mtime)
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
	return (1);
}

int		sort_ascii(t_file *first)
{
	t_file *tmp;
	int action;
	char *swap_ptr;
	t_file *previous;
	t_file *yolo;

	action = 1;
	if (!tmp)
		return (0);
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
		}
	}
	return (1);
}

int		ft_sort(t_file *first, t_option option)
{
	if (option.t)
		sort_time(first);
	else
		sort_ascii(first);

	return (0);
}
