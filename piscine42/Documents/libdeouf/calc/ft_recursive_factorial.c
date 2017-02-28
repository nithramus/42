/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 08:21:38 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/09 13:35:41 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int ret;

	ret = 1;
	if ((nb < 0) || (nb > 12))
		return (0);
	if (nb > 1)
	{
		nb--;
		ret = ft_recursive_factorial(nb);
		ret = ret * (nb + 1);
	}
	return (ret);
}
