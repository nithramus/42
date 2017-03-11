/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:36:59 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 00:25:52 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		fill_att(const char *s, t_info **info, size_t *i)
{
	size_t	n;

	n = 0;
	while (s[*i] == '#' || s[*i] == '0' || s[*i] == '+'
			|| s[*i] == '-' || s[*i] == ' ')
	{
		*i = *i + 1;
		n++;
	}
	if (n > 0)
	{
		(*info)->att = (char*)malloc(sizeof(char) * n + 1);
		(*info)->att = ft_strncpy((*info)->att, s, n);
	}
}

void		fill_pre(const char *s, t_info **info, size_t *i)
{
	if (s[*i] == '.')
	{
		*i = *i + 1;
		(*info)->pre = ft_atoi(s + *i);
	}
	while (s[*i] >= '0' && s[*i] <= '9')
		*i = *i + 1;
}

void		fill_m_longer(const char *s, t_info **info, size_t *i)
{
	size_t	n;

	n = 0;
	if (s[*i + n] == 'h' || s[*i + n] == 'l' || s[*i + n] == 'j'
			|| s[*i + n] == 'z')
	{
		n++;
		if (s[*i + n] == 'h' || s[*i + n] == 'l' || s[*i + n] == 'j'
				|| s[*i + n] == 'z')
		{
			n++;
			(*info)->m_longer = (char*)malloc(sizeof(char) * n + 1);
			(*info)->m_longer[0] = s[*i + 0];
			(*info)->m_longer[1] = s[*i + 1];
		}
		else
		{
			(*info)->m_longer = (char*)malloc(sizeof(char) * 2);
			(*info)->m_longer[0] = s[*i + 0];
		}
		(*info)->m_longer[n] = '\0';
	}
	*i = *i + n;
}

size_t		fill_info(const char *s, t_info **info)
{
	size_t		nb;

	nb = 0;
	fill_att(s, info, &nb);
	if (s[nb] >= '0' && s[nb] <= '9')
		(*info)->f_larger = ft_atoi(s + nb);
	while (s[nb] >= '0' && s[nb] <= '9')
		nb = nb + 1;
	fill_pre(s, info, &nb);
	fill_m_longer(s, info, &nb);
	(*info)->conv = s[nb];
	nb = nb + 1;
	return (nb);
}

t_info		*info_init(t_info *info)
{
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	info->att = NULL;
	info->f_larger = -1;
	info->pre = -1;
	info->m_longer = NULL;
	info->conv = 0;
	return (info);
}
