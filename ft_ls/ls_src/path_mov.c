/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:04:05 by bandre            #+#    #+#             */
/*   Updated: 2017/05/03 00:14:42 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*create_file(char stock[4097], t_option option, int ptr, char *name)
{
	t_file *new;

	if (name[0] == '.' && option.a == 0)
		return (NULL);
	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	if (!(new->file = malloc(ft_strlen(name) + 1)))
		return (NULL);
	ft_strcpy(new->file, name);
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
	show_dir();
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

	ptr = ft_strlen(stock);
	stock[ptr] = '/';
	ptr++;
	stock[ptr] = '\0';
	ft_putendl(stock);
	if (option.rmaj)
	{
		if (!(file_stock = stock_file(stock, option, ptr)))
			return (1);
		next = file_stock;
		while (next)
		{
			ft_putendl(next->file);
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
