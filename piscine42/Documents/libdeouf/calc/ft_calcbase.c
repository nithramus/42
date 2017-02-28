/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:26:42 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/21 15:42:00 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sous(int a, int b)
{
	return (a - b);
}

int		ft_mult(int a, int b)
{
	return (a * b);
}

int		ft_div(int a, int b)
{
	if (b == 0)
		write(2, "Stop : division by zero", 23);
	else
		return (a / b);
	return (NULL);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
		write(2, "Stop : modulo by zero", 21);
	else
		return (a % b);
	return (NULL);
}
