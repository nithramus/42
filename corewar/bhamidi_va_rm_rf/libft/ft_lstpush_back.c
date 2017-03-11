/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:20:22 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/12 13:06:13 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpush_back(t_list *ptr, t_list *elem)
{
	t_list	*t;

	t = ptr;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ft_lstnew(elem->content, elem->content_size);
	return (t);
}
