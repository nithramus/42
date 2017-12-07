/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:44:20 by bandre            #+#    #+#             */
/*   Updated: 2017/05/15 17:06:08 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	t_option	option;
	char		**files;
	int			i;
	char stock[4097];
	int show;
	t_file		*new;

	show = 0;
	i = get_option(argc, argv, &option);
	if (i + 2 <= argc)
		show = 1;
	if (i < argc)
	{
		while (i < argc)
		{
			ft_strcpy(stock, argv[i]);
			if (!(new = create_file(stock, option, 0, argv[i])))
				i = i + 1 - 1;
			else if (!(S_ISDIR(new->info.st_mode)))
				show_dir(new, stock, 1, option);
			else
				path_mov(stock, option, ft_strlen(stock), show);
			i++;
		}
	}
	else
	{
		ft_strcpy(stock, ".");
		path_mov(stock, option, ft_strlen(stock), 0);
	}
	quit_clean(0);
	return (0);
}
