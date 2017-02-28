/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 17:34:07 by tmilon            #+#    #+#             */
/*   Updated: 2016/07/17 05:03:03 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		detect_error(char **argv)
{
	int i;
	int z;

	i = 1;
	z = 0;
	while (argv[i])
	{
		while (argv[i][z])
			z++;
		if (z != 9)
			return (0);
		z = 0;
		i++;
	}
	if (i != 10)
		return (0);
	else
		return (1);
}

void	affichage(char **argv)
{
	int i;
	int z;

	i = 0;
	z = 0;
	if ((detect_error(argv)))
	{
		while (argv[i])
		{
			while (argv[i][z])
			{
				ft_putchar(argv[i][z]);
				if (argv[i][z + 1] == '\0')
					ft_putchar('\n');
				else
					ft_putchar(' ');
				z++;
			}
			z = 0;
			i++;
		}
	}
	else
		write(1, "Erreur\n", 7);
}
