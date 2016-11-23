/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:36:36 by bandre            #+#    #+#             */
/*   Updated: 2016/11/23 01:19:03 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*put_line(t_list **firstelem, int *ret)
{
	int len;
	char *line;
	t_list *elem;
	char *n;

	elem = *firstelem;
	len = 0;
	while (elem)
	{
		len += elem->content_size;
		elem = elem->next;
	}
	elem = *firstelem;
	line = (char*)malloc(len * sizeof(char) + 1);
	while (elem->next)
	{
		ft_strcat(line, &((const char*)elem->content)[elem->is_n]);
		elem = elem->next;
	}
	n = ft_strchr(&((char*)elem->content)[elem->is_n], '\n');
	if (n)
	{
		ft_strncat(line, &((const char*)elem->content)[elem->is_n],
				(n - &((char*)elem->content)[elem->is_n]));
		elem->is_n += (n - &((char*)elem->content)[elem->is_n]) + 1;
	}
	else
	{
		ft_strcat(line, &((const char*)elem->content)[elem->is_n]);
		elem = NULL;
	}
	*firstelem = elem;
	*ret = 1;
	return (line);
}

t_list	*add_read(int fd, int *ret)
{
	char buff[BUFF_SIZE + 1];
	t_list *firstelem;
	t_list *elemnext;

	firstelem = NULL;
	*ret = read(fd, buff, BUFF_SIZE);
	if (ret <= 0)
		return (NULL);
	buff[*ret] = '\0';
	firstelem = ft_lstnew(buff, *ret + 1);
	elemnext = firstelem;
	firstelem->is_n = 0;
	if (ft_strchr(buff, '\n') == NULL)
	{
		*ret = read(fd, buff, BUFF_SIZE);
		if (ret < 0)
			return (NULL);
		if (ret == 0)
			return (firstelem);
		while (ft_strchr(buff, '\n') == NULL && *ret > 0)
		{
			buff[*ret] = '\0';
			elemnext->next = ft_lstnew(buff, *ret + 1);
			elemnext = elemnext->next;
			elemnext->is_n = 0;
			*ret = read(fd, buff, BUFF_SIZE);
		}
		elemnext->next = ft_lstnew(buff, *ret);
		elemnext = elemnext->next;
	}
	return (firstelem);
}


int		need_new_read(int fd, t_list **firstelem)
{
	t_list *elem;
	int ret;

	elem = *firstelem;
	if (elem)
	{
		if (ft_strchr(&elem->content[elem->is_n + 1], '\n') != NULL)
			return (1);
	}
	if (elem == NULL)
		*firstelem = add_read(fd, &ret);
	else
		elem->next = add_read(fd, &ret);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list *firstelem = NULL;
	int ret;
	int ret2;

	ret = 1;
	ret = need_new_read(fd, &firstelem);
	if (ret == -1)
		return (-1);
	*line = put_line(&firstelem, &ret2);
	if (ret == 0 && firstelem == NULL)
		return (0);
	return (ret2);
}/*
int		main()
{
	int fd;
	char *ptr;

	fd = open("test", O_RDONLY);
	get_next_line(fd, &ptr);
	ft_putstr(ptr);
	get_next_line(fd, &ptr);
	ft_putstr(ptr);
	get_next_line(fd, &ptr);
	ft_putstr(ptr);
	get_next_line(fd, &ptr);
	ft_putstr(ptr);
	return (0);
}*/
