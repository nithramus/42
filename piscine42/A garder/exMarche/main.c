/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 17:25:57 by bandre            #+#    #+#             */
/*   Updated: 2016/07/17 05:09:53 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		line(char **tab, int x, int y);
int		column(char **tab, int x, int y);
int		square(char **tab, int x, int y);
void	ft_putchar(char c);
int		detect_error(char **argv);
void	affichage(char **argv);

int		ft_recursiv(char **tab, int pos)
{
	int x;
	int y;
	int i;

	i = 1;
	x = pos / 9;
	y = pos % 9;
	if (x == 10 && y == 0)
		return (1);
	if (tab[x][y] != '.')
		return (ft_recursiv(tab, pos + 1));
	while (i <= 9)
	{
		tab[x][y] = i + '0';
		if ((line(tab, x, y) && column(tab, x, y)) && square(tab, x, y))
		{
			if (ft_recursiv(tab, pos + 1))
				return (1);
		}
		i++;
	}
	tab[x][y] = '.';
	i++;
	return (0);
}

int		main(int argc, char **argv)
{
	if (detect_error(argv))
	{
		ft_recursiv(argv, 9);
		affichage(argv);
	}
	else
		write(1, "Erreur\n", 7);
}
