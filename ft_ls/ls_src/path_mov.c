/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:04:05 by bandre            #+#    #+#             */
/*   Updated: 2017/05/03 21:01:13 by bandre           ###   ########.fr       */
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
	if (stat(stock, &new->info) == -1)
	{
		ft_putendl("stat error");
		perror("");
		return (NULL);
	}
	return (new);
}

int		show_dir()
{
	return (0);
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
	closedir(dir);
	//show_dir();
	ft_sort(first, option);
//	show_dir();
	return (first);
}



void do_nothing()
{
}

int		path_mov(char stock[4097], t_option option, int ptr)
{
	struct stat info;
	t_file *file_stock;
	t_file *next;

	ft_putendl("");
	ptr = ft_strlen(stock) - 1;
	stock[ptr] = '/';
	stock[ptr + 1] = '\n';
	stock[ptr + 2] = '\0';
	ft_putstr(stock);
	ptr += 1;
	stock[ptr] = '\0';
	if (option.rmaj)
	{
		if (!(file_stock = stock_file(stock, option, ptr)))
			return (1);
		next = file_stock;
		while (next)
		{
			ft_putstr(next->file);
			if (ft_strcmp(".", next->file) == 0 || ft_strcmp("..", next->file) == 0)
				do_nothing();
			else if (S_ISDIR(next->info.st_mode))
			{
				ft_strcpy(&stock[ptr], next->file);
				path_mov(stock, option, ptr);
			}
			next = next->next;
		}
	}
	return (0);
}
