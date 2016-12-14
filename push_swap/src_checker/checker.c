/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:29:30 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 20:06:15 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_valide(t_checker *a_list, t_checker *b_list)
{
	if (b_list)
		return (0);
	while (a_list)
	{
		if (a_list->next)
			if (a_list->nb > a_list->next->nb)
				return (0);
		a_list = a_list->next;
	}
	return (1);
}

int		lecture(t_checker *a_list, t_checker *b_list)
{
	char *s;

	s = NULL;
	while (get_next_line(0, &s))
	{
		ft_printf("%s\n", s);
		if (ft_strcmp("sa", s) == 0 || ft_strcmp("ss", s) == 0)
			op_swap(a_list);
		if (ft_strcmp("sb", s) == 0 || ft_strcmp("ss", s) == 0)
			op_swap(b_list);
		if (ft_strcmp("pa", s) == 0)
			op_push(&b_list, &a_list);
		if (ft_strcmp("pb", s) == 0)
			op_push(&a_list, &b_list);
		if (ft_strcmp("ra", s) == 0 || ft_strcmp("rr", s) == 0)
			op_rotate(&a_list);
		if (ft_strcmp("rb", s) == 0 || ft_strcmp("rr", s) == 0)
			op_rotate(&b_list);
		if (ft_strcmp("rra", s) == 0 || ft_strcmp("rrr", s) == 0)
			op_reverse_rotate(&a_list);
		if (ft_strcmp("rrb", s) == 0 || ft_strcmp("rrr", s) == 0)
			op_reverse_rotate(&b_list);
		free(s);
	}
	return (is_valide(a_list, b_list));
}

int		main(int argv, char **argc)
{
	int			i;
	t_checker	*a_list;
	t_checker	*b_list;

	i = 0;
	b_list = NULL;
	if (argv == 1)
		return (1);
	if (!(a_list = new_list(argv, argc)))
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("alist:%d", a_list->previous->nb);
	i = lecture(a_list, b_list);
	if (i == 0)
		ft_printf("KO");
	else
		ft_printf("OK");
	return (1);
}
