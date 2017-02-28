/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 04:58:08 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/12 16:35:20 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int bac;

	i = 1;
	if ((str[0] >= 'a') && (str[0] <= 'z'))
		str[0] = str[0] - 32;
	while (str[i + 1])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		bac = str[i - 1];
		if ((bac < 'a' || bac > 'z') && (bac > 'Z' || bac < 'A') &&
				(bac > '9' || bac < '0'))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
