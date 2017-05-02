/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:44:20 by bandre            #+#    #+#             */
/*   Updated: 2017/05/02 23:28:05 by bandre           ###   ########.fr       */
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
			path_mov(stock, option, 0);
			i++;
		}
	}
	else
	{
		ft_strcpy(stock, ".");
		path_mov(stock, option, 0);
	}

	return (0);
}
