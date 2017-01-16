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

int		main()
{
	DIR *test;
	char *line;

	test = opendir(".");
	while (get_next_line(test, &line))
	{
		ft_printf(line);
		free(line);
	}
	return (1);
}
