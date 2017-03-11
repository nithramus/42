/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:30:13 by bandre            #+#    #+#             */
/*   Updated: 2017/03/09 15:33:12 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern unsigned char		*g_memory;

void	print_memory(void)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%hhx ", g_memory[i]);
		i++;
	}
	quit_clean(5);
}
