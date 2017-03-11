/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:47:58 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/07 17:29:20 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				verif_nb_separator(int nb_s, char **tab, char *str)
{
	int		i;
	int		op;

	i = -1;
	if (handle_line(str, tab) && !ft_strstr(str, NAME_CMD_STRING)
			&& !ft_strstr(str, COMMENT_CMD_STRING))
		return (1);
	while (tab[++i] != 0)
		if (!get_op_tab(tab[i]))
		{
			op = get_num(tab[i]);
			if (op == 1 || op == 9 || op == 15 || op == 16 || op == 12)
				return ((nb_s != 0) ? 1 : 0);
			if (op == 2 || op == 3 || op == 13)
				return ((nb_s != 1) ? 1 : 0);
			if (op == 4 || op == 5 || op == 6 || op == 7
					|| op == 8 || op == 10 || op == 11 || op == 14)
				return (nb_s != 2 ? 1 : 0);
		}
	return (0);
}

long long int	ft_spec_atoi(const char *str)
{
	long long int		result;
	int					i;
	int					is_neg;

	i = 0;
	result = 0;
	is_neg = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result > 0xffffffff)
			return (0xffffffff);
		i++;
	}
	if (is_neg == -1)
		result = result * -1;
	return (result);
}
