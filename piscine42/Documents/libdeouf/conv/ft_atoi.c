/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:54:25 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/21 15:10:57 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		test(char *str, int i)
{
	if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == ' ')
		i = test(str, i + 1);
	else
	{
		if (str[i] == '+')
			i++;
		else if (str[i] == '-')
			i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int		ret;
	int		i;
	int		mem;

	i = test(str, 0);
	ret = 0;
	mem = i - 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10;
		ret = ret + str[i] - '0';
		i++;
	}
	if (str[mem] == '-')
		ret = -ret;
	return (ret);
}
