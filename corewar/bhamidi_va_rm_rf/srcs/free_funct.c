/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:25:40 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/07 17:27:53 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_str_head(t_stable **head, char **str)
{
	ft_strdel(str);
	free_stable(head);
}

void	free_str_tab(char **str, char ***tab)
{
	free_tab(tab);
	ft_strdel(str);
}

void	free_str_tab_stab(char **str, char ***tab, t_stable **head)
{
	free_str_tab(str, tab);
	free_stable(head);
}

int		get_occurs(char *str, char c)
{
	int		res;
	int		i;

	i = -1;
	res = 0;
	while (str[++i] != '\0')
		if (str[i] == c)
			res++;
	return (res);
}

int		clean_comment(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strchr(str, '#'))
	{
		while (str[i] != '#')
			i++;
		ft_bzero(str + i, ft_strlen(str + i));
	}
	i = -1;
	while (str[++i] != '\0')
		if (str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\r' && str[i] != '\0')
			return (0);
	ft_bzero(str, ft_strlen(str));
	return (1);
}
