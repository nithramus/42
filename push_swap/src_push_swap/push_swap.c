/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:29:30 by bandre            #+#    #+#             */
/*   Updated: 2016/12/11 02:42:19 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argv, char **argc)
{
	int		len;
	t_checker	*a_list;
	t_checker	*b_list;

	len = 0;
	if (argv == 1)
		return (1);
	if (!(a_list = new_list(argv, argc)))
	{
		ft_printf("Error\n");
		return (0);
	}
	b_list = a_list;
	while (a_list)
	{
		len++;
		a_list = a_list->next;
	}
	a_list = b_list;
	b_list = NULL;
	ft_printf("\nvaleur de retour:%d",tri_fusion_ameliore(&a_list, &b_list, len));
	//ft_printf("valeur de retour:%d",tri_fusion(&a_list, &b_list, 'a', len));

	
	return (1);
}
