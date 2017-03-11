/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:52:32 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 15:16:55 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		free_tab(char ***tab)
{
	char	**ptr;
	char	*str;

	str = NULL;
	ptr = *tab;
	if (ptr)
	{
		while (*ptr != 0)
		{
			str = *ptr;
			ptr++;
			ft_strdel(&str);
		}
		free(*tab);
		*tab = NULL;
	}
	return (1);
}

int		check_format(char *str)
{
	char	*value;
	size_t	i;

	i = 0;
	value = NULL;
	if (str[0] != '.')
		return (1);
	while ((str[++i] != '\0' && ft_isalpha(str[i])))
		i++;
	value = ft_strnew(i);
	i = 0;
	while ((str[++i] != '\0' && ft_isalpha(str[i])))
		value[i - 1] = str[i];
	i--;
	while (str[++i] != '\0')
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			return (free_string(&value, 1));
	if (!ft_strcmp("comment", value) || !ft_strcmp("name", value))
		return (free_string(&value, 0));
	return (1);
}

int		check_ending(char *str)
{
	int		i;

	i = 0;
	while (str[++i] != '\0')
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
	return (0);
}

int		get_comment_name(char **t, t_stable **head, char *str, int line)
{
	if (get_occurs(str, '"') != 2 || t[1][0] != '"')
		return (1);
	if (check_ending(ft_strrchr(str, '"')))
		return (1);
	ft_strrchr(str, '"')[0] = '\0';
	if (!ft_strcmp(NAME_CMD_STRING, t[0]))
	{
		if (ft_strlen(ft_strchr(str, '"')) > 128)
			return (1);
		tab_push(head, NAME, ft_strchr(str, '"') + 1, line);
	}
	else
	{
		if (ft_strlen(ft_strchr(str, '"')) > 2048)
			return (1);
		tab_push(head, COMMENT, ft_strchr(str, '"') + 1, line);
	}
	return (0);
}

int		fill_stable(char **tab, t_stable **head, char *str, int line)
{
	int		i;

	i = -1;
	if (!ft_strcmp(NAME_CMD_STRING, tab[0])
			|| !ft_strcmp(COMMENT_CMD_STRING, tab[0]))
		return (get_comment_name(tab, head, str, line));
	while (tab[++i] != 0)
	{
		if (!is_label(tab[i]))
			tab_push(head, LABEL, tab[i], line);
		else if (!get_op_tab(tab[i]))
			tab_push(head, OPCODE, tab[i], line);
		else if (!is_param1(tab[i]))
			tab_push(head, P_REG, tab[i], line);
		else if (!is_param2(tab[i]))
			tab_push(head, P_IND, tab[i], line);
		else if (!is_param3(tab[i]))
			tab_push(head, P_DIR, &tab[i][1], line);
		else
			return (1);
	}
	return (0);
}
