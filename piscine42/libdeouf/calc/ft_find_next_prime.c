/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:19:40 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/21 15:59:19 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_prime(int nb);

int		ft_is_prime(int nb)
{
	int		div;
	int		dd;

	dd = 1;
	if (nb < 2)
		return (0);
	while (dd < nb / dd)
	{
		dd++;
		div = nb / dd;
		if (nb == dd * div)
			return (0);
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int		n;

	n = 0;
	while (n != 1000000)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		n++;
		nb++;
	}
	return (0);
}

int		ft_prime(int nb)
{
	int		div;
	int		dd;

	dd = 1;
	if (nb < 2)
		return (0);
	while (dd < nb / dd)
	{
		dd++;
		div = nb / dd;
		if (nb == dd * div)
			return (0);
	}
	return (1);
}
