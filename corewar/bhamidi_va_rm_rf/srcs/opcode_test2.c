/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_test2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:29:46 by bhamidi           #+#    #+#             */
/*   Updated: 2017/02/25 15:17:45 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		test_sti(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (count_tab(ptr) < 4)
		return (1);
	if (ptr->next->key != P_REG)
		return (1);
	if (ptr->next->next->next->key != P_REG
			&& ptr->next->next->next->key != P_DIR)
		return (1);
	if (ptr->next->next->key != P_DIR && ptr->next->next->key != P_REG
			&& ptr->next->next->key != P_IND)
		return (1);
	*head = ptr->next->next->next;
	return (0);
}

int		test_st(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (count_tab(ptr) < 3)
		return (1);
	if (ptr->next->key != P_REG)
		return (1);
	if (ptr->next->next->key != P_REG && ptr->next->next->key != P_IND)
		return (1);
	*head = ptr->next->next;
	return (0);
}

int		test_load(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (count_tab(ptr) < 3)
		return (1);
	if (ptr->next->next->key != P_REG)
		return (1);
	if (ptr->next->key != P_DIR && ptr->next->key != P_IND)
		return (1);
	*head = ptr->next->next;
	return (0);
}
