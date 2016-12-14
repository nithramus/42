/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:06:13 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 02:25:58 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/ft_printf/ft_printf.h"
#include <limits.h>

typedef struct	s_checker
{
	int			nb;
	struct s_checker	*next;
	struct s_checker	*previous;
}				t_checker;

t_checker		*ft_new_checker(int nb, t_checker *previous);
t_checker		*new_list(int argv, char **argc);
void			ft_free_checker(t_checker *first);
int				*verif_entier(char *argc, int *i);
int				op_swap(t_checker *elem_c);
int				op_push(t_checker **src, t_checker **dest);
int				op_rotate(t_checker **list);
int				op_reverse_rotate(t_checker **list);

int				tri_fusion(t_checker **a_list, t_checker **b_list, char list
		, int len);
int				tri_fusion_ameliore(t_checker **src, t_checker **dest, int len);
int				afficher(t_checker *src, t_checker *dest);
int				*tableau_trie(t_checker *a_list, int len);
int				ft_checker_len(t_checker *src);
int				tri_am(t_checker **src, t_checker **dest, int lensrc, int lendest);
#endif
