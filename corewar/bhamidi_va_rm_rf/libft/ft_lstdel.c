/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:35:58 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/06 17:42:12 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *alst;
	while (ptr)
	{
		del(ptr->content, ptr->content_size);
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	ptr = NULL;
	*alst = ptr;
}
