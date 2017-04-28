/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:44:20 by bandre            #+#    #+#             */
/*   Updated: 2017/04/28 20:18:05 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_option	option;
	char		**files;
	int			i;

	i = get_option(argc, argv, &option);
	printf_option(option);
	if (i < argc)
	{
		while (i < argc)
		{
			path_mov(argv[i], option);
			i++;
		}
	}
	else
	{
		path_mov(".", option);
	}

	return (0);
}
