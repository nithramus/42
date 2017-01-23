/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:13:10 by bandre            #+#    #+#             */
/*   Updated: 2017/01/16 12:14:33 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	DIR *test;
	char *line;
	struct dirent *recup;
	struct stat info;
	struct passwd *uid;
	s_param *param;
	int i;
	char **tab;


	param = recup_param(argv);
	i = 0;
	if (param->list_fichier[0])
	{
		ft_putendl(param->list_fichier[0]);
		while (param->list_fichier[i])
		{
			go_to_dir(param->list_fichier[i], param);
			i++;
		}
	}
	else
	{
		go_to_dir(".", param);
	}
	//go_to_dir(".", param);
	/*test = opendir(".");
	while (recup = readdir(test))
	{
		stat(recup->d_name, &info);
		uid = getpwuid(info.st_uid);
		ft_printf("uid :%s\n", uid->pw_name);
		if (S_ISDIR(info.st_mode))
		{
			ft_printf("un dossier:%s\n ", recup->d_name);
		}
		else
		{
			printf("autre chose:%s\n ", recup->d_name);
		}
	}*/
	return (1);
}
