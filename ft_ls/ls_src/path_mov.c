/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 19:11:04 by bandre            #+#    #+#             */
/*   Updated: 2017/04/28 21:30:51 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *create_path(char *path, char *dir)
{
	char *new;
	int i;

	i = 0;
	if (!(new = mem_stock(ft_strlen(path) + ft_strlen(dir) + 1)))
		quit_clean(1);
	i = ft_strlen(path);
	ft_strncpy(new, path, i);
	new[i] = '/';
	i++;
	ft_strncpy(new + i, dir, ft_strlen(dir) + 1);
	return (new);
}

int		show_dir(char *path, t_option option)
{
	return (0);
}

int		path_mov(char *path, t_option option)
{
	DIR *dir;
	struct dirent *list_elem;
	struct stat info;
	char *new_path;

	ft_putendl("entree");
	show_dir(path, option);
	if (!ft_printf("%s\n",path))
		quit_clean(1);
	if (option.rmaj)
	{
		if (!(dir = opendir(path)))
			quit_clean(4);
		while ((list_elem = readdir(dir)) != NULL)
		{
			new_path = create_path(path, list_elem->d_name);
			if (stat(new_path, &info) == -1)
				quit_clean(4);
			else if (S_ISDIR(info.st_mode) && list_elem->d_name[0] != '.')
				path_mov(new_path, option);
			mem_free_ptr(new_path);
		}
	}
	ft_putendl("sortie path mov");
	return (0);
}
