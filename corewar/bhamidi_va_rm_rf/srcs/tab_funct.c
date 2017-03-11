/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:43:10 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 15:15:47 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_stable	*create_tab(char key, char *value, int line)
{
	t_stable	*tab;

	if (!(tab = (t_stable*)malloc(sizeof(t_stable))))
		return (NULL);
	tab->key = key;
	tab->value = ft_strdup(value);
	tab->next = NULL;
	tab->label_pos = 0;
	tab->line = line;
	return (tab);
}

void		del(t_stable **ptr)
{
	t_stable	*t;

	t = *ptr;
	t->key = 0;
	t->line = 0;
	ft_strdel(&(t->value));
	t->next = NULL;
	free(t);
	*ptr = NULL;
}

int			count_tab(t_stable *ptr)
{
	int		i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void		free_stable(t_stable **head)
{
	t_stable	*ptr;
	t_stable	*tmp;

	tmp = NULL;
	ptr = *head;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		ft_strdel(&(tmp->value));
		del(&tmp);
	}
}

void		tab_push(t_stable **head, char key, char *value, int line)
{
	t_stable	*ptr;

	ptr = *head;
	if (!ptr)
		*head = create_tab(key, value, line);
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = create_tab(key, value, line);
	}
}
