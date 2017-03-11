/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aox2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:40:56 by msrun             #+#    #+#             */
/*   Updated: 2017/03/04 13:27:00 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_xor_fill_reg(unsigned char *tab1, unsigned char *tab2,
		unsigned char *tab3)
{
	tab3[0] = tab1[0] ^ tab2[0];
	tab3[1] = tab1[1] ^ tab2[1];
	tab3[2] = tab1[2] ^ tab2[2];
	tab3[3] = tab1[3] ^ tab2[3];
}

void	ft_or_fill_reg(unsigned char *tab1, unsigned char *tab2,
		unsigned char *tab3)
{
	tab3[0] = tab1[0] | tab2[0];
	tab3[1] = tab1[1] | tab2[1];
	tab3[2] = tab1[2] | tab2[2];
	tab3[3] = tab1[3] | tab2[3];
}

void	ft_and_fill_reg(unsigned char *tab1, unsigned char *tab2,
		unsigned char *tab3)
{
	tab3[0] = tab1[0] & tab2[0];
	tab3[1] = tab1[1] & tab2[1];
	tab3[2] = tab1[2] & tab2[2];
	tab3[3] = tab1[3] & tab2[3];
}
