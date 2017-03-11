/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:54:14 by bhamidi           #+#    #+#             */
/*   Updated: 2017/02/24 20:50:54 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		test_xor_or(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (count_tab(ptr) < 4)
		return (1);
	if (ptr->next->next->next->key != P_REG)
		return (1);
	if (ptr->next->next->key != P_REG && ptr->next->next->key != P_DIR
			&& ptr->next->next->key != P_IND)
		return (1);
	if (ptr->next->key != P_REG && ptr->next->key != P_DIR
			&& ptr->next->key != P_IND)
		return (1);
	*head = ptr->next->next->next;
	return (0);
}

int		test_add_sub(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (count_tab(ptr) < 4)
		return (1);
	if (ptr->next->key != P_REG)
		return (1);
	if (ptr->next->next->key != P_REG)
		return (1);
	if (ptr->next->next->next->key != P_REG)
		return (1);
	*head = ptr->next->next->next;
	return (0);
}

int		test_ldi(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (count_tab(ptr) < 4)
		return (1);
	if (ptr->next->next->next->key != P_REG)
		return (1);
	if (ptr->next->key != P_DIR && ptr->next->key != P_REG
			&& ptr->next->key != P_IND)
		return (1);
	if (ptr->next->next->key != P_REG && ptr->next->next->key != P_DIR)
		return (1);
	*head = ptr->next->next->next;
	return (0);
}

int		test_aff(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (!ptr->next)
		return (1);
	if (ptr->next->key != P_REG)
		return (1);
	*head = ptr->next;
	return (0);
}

int		test_only_dir(t_stable **head)
{
	t_stable	*ptr;

	ptr = *head;
	if (!ptr->next)
		return (1);
	if (ptr->next->key != P_DIR)
		return (1);
	*head = ptr->next;
	return (0);
}
