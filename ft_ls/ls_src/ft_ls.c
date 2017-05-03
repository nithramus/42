/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:44:20 by bandre            #+#    #+#             */
/*   Updated: 2017/05/03 18:40:26 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_option	option;
	char		**files;
	int			i;
	char stock[4097];

	i = get_option(argc, argv, &option);
	printf_option(option);
	if (i < argc)
	{
		while (i < argc)
		{
			ft_strcpy(stock, argv[i]);
			stock[ft_strlen(argv[i])] = '\n';
			stock[ft_strlen(argv[i]) + 1] = '\0';
			path_mov(stock, option, 0);
			i++;
		}
	}
	else
	{
		ft_strcpy(stock, ".\n");
		path_mov(stock, option, 0);
	}

	return (0);
}
