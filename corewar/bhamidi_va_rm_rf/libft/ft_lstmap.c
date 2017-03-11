/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:20:16 by bhamidi           #+#    #+#             */
/*   Updated: 2016/11/10 10:20:08 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstadd_t(t_list *alst, t_list *new_ptr)
{
	if (new_ptr != NULL)
		new_ptr->next = alst;
	return (new_ptr);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*t;
	int		first;

	first = 1;
	ptr = NULL;
	t = NULL;
	if (lst != NULL)
	{
		while (lst)
		{
			if (first == 1)
			{
				t = f(lst);
				ptr = ft_lstadd_t(ptr, t);
				first = 0;
			}
			else
				ptr = ft_lstpush_back(ptr, f(lst));
			lst = lst->next;
		}
	}
	return (ptr);
}
