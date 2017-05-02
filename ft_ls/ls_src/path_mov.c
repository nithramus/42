/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 19:11:04 by bandre            #+#    #+#             */
/*   Updated: 2017/04/29 21:05:53 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *create_path(char *path, char *dir)
{
	char *new;
	int len_dir;
	int len_path;

	len_dir = ft_strlen(dir);
	len_path = ft_strlen(path);
	if (!(new = mem_stock(len_path + len_dir + 2)))
		quit_clean(1);
	ft_strncpy(new, path, len_path);
	new[len_path] = '/';
	ft_strncpy(new + len_path + 1, dir, len_dir);
	new[len_dir + len_path + 1] = '\0';
	return (new);
}

t_mem_stock	*stock_file(char *path)
{
	DIR *dir;
	t_mem_stock **ptr;
	struct dirent *list_elem;
	struct stat info;
	char *new_path;

	ptr = mem_ptr();
	*ptr = NULL;
	if (!(dir = opendir(path)))
	{
		perror("");
		ft_putendl("opendir failed");
	}
	while ((list_elem = readdir(dir)) != NULL)
	{
		new_path = create_path(path, list_elem->d_name);
		if (stat(new_path, &info) == -1)
		{
			ft_putendl(new_path);
			perror("");
			mem_free_ptr(new_path);
		}
		else if (!S_ISDIR(info.st_mode) || list_elem->d_name[0] == '.')
			mem_free_ptr(new_path);
	}
	closedir(dir);
	ptr = mem_ptr();
	return (*ptr);
}



int		show_dir(char *path, t_option option)
{
	return (0);
}

int		path_mov(char *path, t_option option)
{
	t_mem_stock *file_stock;
	int j;
	t_mem_stock *next;

	show_dir(path, option);
	if (!ft_printf("%s\n",path))
		quit_clean(1);
	if (option.rmaj)
	{
		file_stock = stock_file(path);
		next = file_stock;
		while (next)
		{
		j = 0;
			while (j < 50)
			{
				if (next->list_ptr[j])
					path_mov(next->list_ptr[j], option);
				j++;
			}
			next = next->next;
		}
	}
	ft_putendl("sortie path mov");
	return (0);
}
