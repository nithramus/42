/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:13:57 by bandre            #+#    #+#             */
/*   Updated: 2017/03/09 01:46:16 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			parse_dump(int *dump, int *visu, int argc, char **argv)
{
	int i;

	i = 1;
	*dump = -1;
	*visu = -1;
	while (i < argc)
	{
		if (ft_strcmp("-dump", argv[i]) == 0)
		{
			i++;
			if (i < argc && ft_is_number(argv[i]) && *dump == -1)
			{
				if (ft_strlen(argv[i]) >= 14 ||
						ft_atoi(argv[i]) < 0 || ft_atoi(argv[i]) > INT_MAX)
					quit_clean(2);
				else
					*dump = ft_atoi(argv[i]);
			}
			else
				quit_clean(2);
		}
		if (ft_strcmp("-v", argv[i]) == 0)
			*visu = 1;
		i++;
	}
}

static void		init(t_parse *joueurs)
{
	int i;

	i = 0;
	while (i < 4)
	{
		joueurs[i].num = 0;
		joueurs[i].fichier = NULL;
		i++;
	}
}

void			par_extend(int *i, int *tab, t_parse *joueurs,
		int argc, char **argv)
{
	if (ft_strcmp("-dump", argv[*i]) == 0)
		*i += 1;
	else if (ft_strcmp("-v", argv[*i]) == 0)
		*i = *i + 1 - 1;
	else if (ft_strcmp("-n", argv[*i]) == 0)
	{
		(*i)++;
		if (*i + 1 < argc && ft_is_number(argv[*i]))
		{
			joueurs[*tab].num = ft_atoi(argv[*i]);
			joueurs[*tab].fichier = argv[*i + 1];
			(*tab)++;
			(*i)++;
		}
		else
			quit_clean(2);
	}
	else
	{
		joueurs[*tab].num = -(*tab + 1);
		joueurs[*tab].fichier = argv[*i];
		(*tab)++;
	}
}

t_parse			*parse_number(int *dump, int *visu, int argc, char **argv)
{
	int			i;
	t_parse		*joueurs;
	int			tab;

	tab = 0;
	i = 1;
	if (!(joueurs = (t_parse*)malloc(sizeof(t_parse) * 4)))
		quit_clean(1);
	init(joueurs);
	parse_dump(dump, visu, argc, argv);
	while (i < argc)
	{
		par_extend(&i, &tab, joueurs, argc, argv);
		i++;
	}
	if (tab == 0 || tab > 4)
		quit_clean(2);
	return (joueurs);
}
