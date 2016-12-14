/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:06:13 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 18:18:39 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct			s_checker
{
	int					nb;
	struct s_checker	*next;
	struct s_checker	*previous;
}						t_checker;

t_checker				*ft_new_checker(int nb, t_checker *previous);
t_checker				*new_list(int argv, char **argc);
void					ft_free_checker(t_checker *first);
int						*verif_entier(char *argc, int *i);
int						op_swap(t_checker *elem_c);
int						op_push(t_checker **src, t_checker **dest);
int						op_rotate(t_checker **list);
int						op_reverse_rotate(t_checker **list);
#endif
