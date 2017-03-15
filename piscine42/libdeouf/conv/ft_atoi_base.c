/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 20:08:18 by exam              #+#    #+#             */
/*   Updated: 2016/07/21 15:34:51 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char g_e[] = "0123456789abcdef";
char g_d[] = "0123456789ABCDEF";

int		ft_appart(char c, int str_base)
{
	int i;

	i = 0;
	while (i < str_base)
	{
		if (c == g_e[i] || c == g_d[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_chaine_valide(const char *str, int str_base, int *neg)
{
	int nb;
	int i;

	i = 0;
	while (ft_appart(str[i], str_base) == -1)
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			nb = 0;
		else if (str[i] == '-' && i == 0)
		{
			if (ft_appart(str[i + 1], str_base))
				*neg = 1;
			else
				return (-1);
		}
		else if (str[i] == '+')
		{
			if (!(ft_appart(str[i + 1], str_base) != -1))
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (i);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int i;
	int nb;
	int neg;

	neg = 0;
	nb = 0;
	i = ft_chaine_valide(str, str_base, &neg);
	if (i != -1)
	{
		while (ft_appart(str[i], str_base) != -1)
		{
			nb = nb * str_base + ft_appart(str[i], str_base);
			i++;
		}
	}
	if (neg)
		nb = nb * -1;
	return (nb);
}
