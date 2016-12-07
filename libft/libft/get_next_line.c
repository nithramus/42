/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:04:14 by bandre            #+#    #+#             */
/*   Updated: 2016/12/07 18:16:56 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*put_line(t_list **elem, int *pos, char **line)
{
	char	*n;
	t_list	*elem_avant;

	while ((*elem)->next && (elem_avant = *elem))
	{
		ft_strcat(*line, &((const char*)(*elem)->content)[*pos]);
		*elem = (*elem)->next;
		free(elem_avant->content);
		free(elem_avant);
		*pos = 0;
	}
	if ((n = ft_strchr(&((char*)(*elem)->content)[*pos], '\n')) && n)
	{
		ft_strncat(*line, &((const char*)(*elem)->content)[*pos],
				(n - &((char*)(*elem)->content)[*pos]));
		*pos = (n - &((char*)(*elem)->content)[0]) + 1;
	}
	else
	{
		ft_strcat(*line, &((const char*)(*elem)->content)[*pos]);
		free((*elem)->content);
		free(*elem);
		*elem = NULL;
	}
	return (*line);
}

t_list	*add_read(int fd, int *ret, int cont, t_list *firstelem)
{
	char	buff[BUFF_SIZE + 1];
	t_list	*elemnext;

	*ret = read(fd, buff, BUFF_SIZE);
	while (*ret > 0 && cont == 1)
	{
		buff[*ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
			cont = 0;
		if (!firstelem)
		{
			firstelem = ft_lstnew(buff, *ret + 1);
			elemnext = firstelem;
		}
		else
		{
			elemnext->next = ft_lstnew(buff, *ret + 1);
			elemnext = elemnext->next;
		}
		if (cont)
			*ret = read(fd, buff, BUFF_SIZE);
	}
	if (*ret < 0)
		return (NULL);
	return (firstelem);
}

int		need_new_read(int fd, t_list **firstelem, int n)
{
	t_list	*elem;
	int		ret;
	int		cont;
	t_list	*anelem;

	anelem = NULL;
	cont = 1;
	elem = *firstelem;
	if (elem)
	{
		if (ft_strchr(&elem->content[n], '\n') != NULL)
			return (1);
	}
	if (elem == NULL)
	{
		elem = add_read(fd, &ret, cont, anelem);
		if (elem)
			*firstelem = elem;
	}
	else
		elem->next = add_read(fd, &ret, cont, anelem);
	return (ret);
}

int		get_next(const int fd, char **line, t_list **firstelem, int *n)
{
	char			line2;
	int				len;
	t_list			*elem;

	if (need_new_read(fd, firstelem, *n) == -1)
		return (-1);
	line2 = '\0';
	*line = &line2;
	if (!*firstelem)
		return (0);
	if ((*firstelem)->next || ((char*)(*firstelem)->content)[*n] != '\0')
	{
		elem = *firstelem;
		len = elem->content_size;
		while ((elem = elem->next) && elem)
			len += elem->content_size;
		if (!(*line = ft_strnew(len + 1)))
			return (-1);
		put_line(firstelem, n, line);
	}
	else
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_listchain	*first = NULL;
	t_listchain			*list_fd;
	t_listchain			*listmal;
	int ret;

	list_fd = first;
	while (list_fd)
	{
		if (list_fd->fd == fd)
		{
			ret = get_next(fd, line, &(list_fd->firstelem), &(list_fd->n));
			if (ret == 0)
			{
				listmal = list_fd->next;
				free(list_fd);
				list_fd = listmal;
				return (ret);
			}
		list_fd = list_fd->next;
		}
	}
	if (!(listmal = (t_listchain*)malloc(sizeof(t_listchain))))
		return (0);
	if ((list_fd = first) && first)
		while (list_fd->next)
			list_fd = list_fd->next;
	if (first && (listmal->fd = fd))
		list_fd->next = listmal;
	else
		first = listmal;
	listmal->n = 0;
	listmal->next = NULL;
	listmal->firstelem = NULL;
	return (get_next(fd, line, &(listmal->firstelem), &(listmal->n)));
}
