/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 19:14:06 by bandre            #+#    #+#             */
/*   Updated: 2017/04/28 20:06:38 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	add_option(t_option *option, char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr("alrRt", (int)str[i]))
		{
			if (str[i] == 'r' )
				option->r = 1;
			if (str[i] ==  'R')
				option->rmaj = 1;
			if (str[i] ==  'a')
				option->a = 1;
			if (str[i] ==  'l')
				option->l = 1;
			if (str[i] ==  't')
				option->t = 1;
		}
		else
			quit_clean(2);
		i++;
	}
	return (1);
}


int			get_option(int argc, char **argv, t_option *option)
{
	int i;

	option->r = 0;
	option->rmaj = 0;
	option->a = 0;
	option->l = 0;
	option->t = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--") == 0)
			break ;
		if (argv[i][0] == '-')
			add_option(option, argv[i]);
		else
			break ;
		i++;
	}
	return (i);
}



