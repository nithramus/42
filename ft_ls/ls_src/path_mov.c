/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:04:05 by bandre            #+#    #+#             */
/*   Updated: 2017/05/15 16:41:10 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

t_file	*create_file(char stock[4097], t_option option, int ptr, char *name)
{
	t_file *new;
	int size;

	size = ft_strlen(name);
	if (name[0] == '.' && option.a == 0)
		return (NULL);
	if (!(new = mem_stock(sizeof(t_file) + size + 3)))
		return (NULL);
	new->file = (char*)&new[1];
	ft_strcpy(new->file, name);
	new->file[size] = '\0';
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
	show_dir(first, stock, ptr, option);

	return (first);
}

int		path_mov(char stock[4097], t_option option, int ptr, int show)
{
	struct stat info;
	t_file *file_stock;
	t_file *next;

	stock[ptr] = '\0';
	if (show){
		ft_putstr(stock);
		ft_putendl(":");
	}
	stock[ptr] = '/';
	ptr += 1;
	stock[ptr] = '\0';


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
				stock[ptr + 1] = '\0';
				ft_strcpy(&stock[ptr], next->file);
				path_mov(stock, option, ft_strlen(stock), 1);
			}
			next = next->next;
		}
	}
	return (0);
}
