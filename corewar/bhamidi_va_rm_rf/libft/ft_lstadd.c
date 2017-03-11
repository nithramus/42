/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:43:08 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/09 15:48:33 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new_ptr)
{
	t_list	*ptr;

	if (new_ptr != NULL)
	{
		ptr = *alst;
		new_ptr->next = ptr;
		*alst = new_ptr;
	}
}
