/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:04:05 by bandre            #+#    #+#             */
/*   Updated: 2017/05/15 15:17:00 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*create_file(char stock[4097], t_option option, int ptr, char *name)
{
	t_file *new;
	int size;

	size = ft_strlen(name);
	if (name[0] == '.' && option.a == 0)
		return (NULL);
	if (!(new = malloc(sizeof(t_file) + size + 3)))
		return (NULL);
	new->file = (char*)&new[1];
	ft_strcpy(new->file, name);
	new->file[size] = '\n';
	new->file[size + 1] = '\0';
	new->next = NULL;
	ft_strcpy(&stock[ptr], name);
	if (lstat(stock, &new->info) == -1)
	{
		ft_putendl("stat error");
		perror("");
		return (NULL);
	}
	return (new);
}

void do_nothing()
{
}

static t_file	*stock_file(char stock[4097], t_option option, int ptr)
{
	DIR *dir;
	struct dirent *list_elem;
	t_file *first;
	t_file *tmp;

	first = NULL;
	if (!(dir = opendir(stock)))
	{
	perror("");
		return (NULL);
	}
	while ((list_elem = readdir(dir)))
	{
		if (list_elem->d_name[0] == '.' && option.a != 1)
			do_nothing();
		else
		{
			if (first)
			{
				if ((tmp->next = create_file(stock, option, ptr, list_elem->d_name)))
					tmp = tmp->next;
			}
			else
			{
				if ((first = create_file(stock, option, ptr, list_elem->d_name)))
					tmp = first;
			}
		}
	}
	closedir(dir);
	ft_sort(&first, option);
	if (option.l)
		show_dir(first, stock, ptr);
	else
	{
		tmp = first;
		while (tmp)
		{
			ft_putstr(tmp->file);
			tmp = tmp->next;
		}
	}
	return (first);
}



int		path_mov(char stock[4097], t_option option, int ptr)
{
	struct stat info;
	t_file *file_stock;
	t_file *next;

	stock[ptr] = '/';
	ptr += 1;
	stock[ptr] = '\0';
	ft_putendl(stock);

	if (!(file_stock = stock_file(stock, option, ptr)))
		return (1);
	if (option.rmaj)
	{

		next = file_stock;
		while (next)
		{
			if (ft_strcmp(".\n", next->file) == 0 || ft_strcmp("..\n", next->file) == 0)
				do_nothing();
			else if (S_ISDIR(next->info.st_mode))
			{
				ft_putendl("");
				stock[ptr] = '\n';
				stock[ptr + 1] = '\0';
				stock[ptr] = '\0';
				ft_strcpy(&stock[ptr], next->file);
				path_mov(stock, option, ft_strlen(stock) - 1);
			}
			next = next->next;
		}
	}
	return (0);
}
