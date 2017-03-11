/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 07:48:46 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/31 16:31:27 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*func_gene(char *str, char **line)
{
	size_t	i;
	char	*t;

	t = NULL;
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n') != NULL)
	{
		i = 0;
		while (str[i] != '\n')
			i++;
		*line = ft_strnew(i);
		*line = ft_strncpy(*line, str, i);
		t = ft_strsub(str, i + 1, (ft_strlen(str) - i));
	}
	else
		*line = ft_strdup(str);
	return (t);
}

char	*have_nl_tmp(char *str, char *tmp, char **line)
{
	char	*t;

	t = NULL;
	t = ft_strjoin(str, tmp);
	ft_strdel(&str);
	str = func_gene(t, line);
	ft_strdel(&t);
	return (str);
}

void	have_ret(const int fd, char **line, char **str, char *tmp)
{
	char	*t;

	t = NULL;
	if (ft_strchr(*str, '\n') != NULL)
	{
		t = func_gene(*str, line);
		*str = ft_strjoin(t, tmp);
		ft_strdel(&t);
	}
	else if (ft_strchr(tmp, '\n') != NULL)
		*str = have_nl_tmp(*str, tmp, line);
	else
	{
		t = ft_strjoin(*str, tmp);
		ft_strdel(str);
		*str = ft_strdup(t);
		ft_strdel(&t);
		get_next_line(fd, line);
	}
}

void	only_ret(const int fd, char **line, char *tmp, char **str)
{
	if (ft_strchr(tmp, '\n') != NULL)
		*str = func_gene(tmp, line);
	else
	{
		*str = ft_strdup(tmp);
		get_next_line(fd, line);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	char			buf[BUFF_SIZE];
	char			*tmp;
	ssize_t			ret;

	tmp = NULL;
	if (BUFF_SIZE == 0)
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if ((ret == 0 && str == NULL) || (ret == 0 && ft_strlen(str) == 0))
		return (0);
	if (ret == 0)
		str = func_gene(str, line);
	if (ret > 0)
	{
		tmp = ft_strnew(ret);
		tmp = ft_strncpy(tmp, buf, ret);
		if (str)
			have_ret(fd, line, &str, tmp);
		else
			only_ret(fd, line, tmp, &str);
	}
	ft_strdel(&tmp);
	return (1);
}
