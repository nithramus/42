/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 15:12:43 by bandre            #+#    #+#             */
/*   Updated: 2016/07/28 15:31:56 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
	int tab[8];
	unsigned char op;
	int i;
	int tmp;

	i = 0;
	while (i < 8)
	{
		tmp = octet % 2;
		tab[i] = tmp;
		octet = octet / 2;
		printf("%d\n", tab[i]);
		i++;
	}
	op = 0;
	i = 0;
	while (i < 8)
	{
		op = op * 2 + tab[i];
		i++;
	}
	return (op);
}

int main()
{
	unsigned char c;
	c = reverse_bits(15);
	printf("%d", c);
}
