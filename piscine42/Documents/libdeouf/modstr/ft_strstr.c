/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:22:49 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/12 03:09:57 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		stlen(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	ver(char *str, char *to_find, int mem)
{
	int comp;

	comp = 0;
	while (str[comp + mem] == to_find[comp] || to_find[comp] == 0)
	{
		if (to_find[comp] == 0)
			return (1);
		comp++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	if (to_find == 0 || str == 0)
		return (str);
	if (stlen(str) < stlen(to_find))
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			if (ver(str, to_find, i) == 1)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
