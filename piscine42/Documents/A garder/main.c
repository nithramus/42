/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:32:32 by bandre            #+#    #+#             */
/*   Updated: 2016/07/27 19:15:04 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_exploit(t_tabval **tabstruct, int *var, char **tab, char *carac)
{
	int size;
	int posx;
	int posy;
	int pos[2];

	posx = var[1];
	posy = var[0];
	size = ft_carepos(tabstruct, &posx, &posy);
	pos[1] = posx;
	pos[0] = posy;
	add_x(tab, pos, size, carac);
	ft_printbsq(tab, var[1], var[0]);
	return (size);
}

int		ft_compti(char *chaine)
{
	int		i;

	i = 0;
	while (chaine[i] && chaine[i] != '\n')
		i++;
	i++;
	return (i);
}

int		ft_test_valide(char *chaine)
{
	int i;
	int nb_ligne;
	int size_column;

	nb_ligne = 0;
	i = ft_compti(chaine);
	size_column = ft_count_column(&chaine[i]);
	while (chaine[i])
	{
		if (chaine[i] == '\n')
		{
			nb_ligne++;
			i++;
			if (size_column != ft_count_column(&chaine[i]) &&
					ft_count_column(&chaine[i]) != '\0')
				return (0);
		}
		else
			i++;
	}
	if (nb_ligne != 0 && size_column != 0)
		return (1);
	return (0);
}

int		main_recherche(int fd)
{
	int			var[2];
	char		*chaine;
	char		**tab;
	t_tabval	**tabstruct;
	char		carac[3];

	chaine = ft_receive_tab(&var[1], fd, carac);
	if (!ft_test_valide(chaine))
	{
		ft_putstr("map error\n");
		return (0);
	}
	tab = copy_tab(chaine);
	var[0] = ft_strlen(tab[0]);
	tabstruct = ft_remptab(var[1], var[0], tab, carac);
	ft_exploit(tabstruct, var, tab, carac);
	ft_freetabstruc(tabstruct, var[1]);
	ft_destroydd(tab);
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;
	int i;

	i = 1;
	if (argc == 1)
	{
		main_recherche(0);
		return (0);
	}
	else if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr("open() error ");
				ft_putstr(argv[i]);
				ft_putstr("\n");
			}
			 else
			 {
				 main_recherche(fd);
				if (close(fd) == -1)
				{
					ft_putstr("close() error");
					ft_putstr(argv[i]);
					ft_putstr("\n");
				}
			 }
			 i++;
		}
	}
}
