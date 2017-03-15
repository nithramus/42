/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:40:41 by bandre            #+#    #+#             */
/*   Updated: 2016/12/05 00:47:21 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier_pourcent(t_param *list)
{
	char *s;

	s = ft_strnew(2);
	if (!s)
		return (NULL);
	list->space = 0;
	s[0] = '%';
	return (s);
}

int		ft_affichage(t_param list, va_list ap)
{
	char	*s;
	int		value;

	value = 0;
	s = NULL;
	if (ft_strchr("DOUCS", list.specifier))
		list.longueur = 'l';
	if (ft_strchr("idD", list.specifier))
		s = specifier_i(list, ap);
	else if (list.specifier == 'u' || list.specifier == 'U')
		s = specifier_uox(list, ap, 10, 0);
	else if (list.specifier == 'o' || list.specifier == 'O')
		s = specifier_uox(list, ap, 8, 0);
	else if (list.specifier == 'x')
		s = specifier_uox(list, ap, 16, 0);
	else if (list.specifier == 'X')
		s = specifier_uox(list, ap, 16, 1);
	else if (list.specifier == 'p')
		s = specifier_uox(list, ap, 16, 0);
	else if (list.specifier == 'c' || list.specifier == 'C')
		s = specifier_c(&list, ap, &value);
	else if (list.specifier == 'S' || list.specifier == 's')
		s = specifier_s(list, ap);
	else if (list.specifier == '%')
		s = specifier_pourcent(&list);
	else if (!s)
		return (-1);

	s = ft_casp(list, s);
	s = ft_gestion_attrib_diese(list, s);
	s = ft_gestion_precision(list, s);
	s = ft_gestion_attrib_plus(list, s);
	s = ft_gestion_attrib_moins(list, s);
	if (!s)
		return (-1);
	value = ft_strlen(s) + value;
	ft_putstr(s);
	return (value);
}
