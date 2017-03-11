/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:21:22 by bandre            #+#    #+#             */
/*   Updated: 2017/03/11 18:08:55 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	big_endian(int r1)
{
	char			*buff;
	char			test[4];
	unsigned int	*header;
	unsigned int	*ret;

	buff = (char*)&r1;
	test[0] = buff[3];
	test[1] = buff[2];
	test[2] = buff[1];
	test[3] = buff[0];
	ret = (unsigned int*)test;
	return (*ret);
}

t_process		*new_t_process(int r1, int nb_joueurs,
		t_process *next, t_process *previous)
{
	t_process	*new;
	int			*ptr;

	if (!(new = (t_process*)ft_strnew(sizeof(t_process))))
		quit_clean(1);
	ptr = (int*)new->registre[0];
	*ptr = big_endian(r1);
	new->live = 0;
	new->carry = 0;
	new->op_code = 0;
	new->next = next;
	new->cycle = 0;
	new->act_cycle = 0;
	new->previous = previous;
	return (new);
}
