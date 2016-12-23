/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:06:13 by bandre            #+#    #+#             */
/*   Updated: 2016/12/14 01:47:22 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int						tri_fusion_ameliore(t_checker **src,
		t_checker **dest, int le);
int						afficher(t_checker *src, t_checker *dest);
int						ft_checker_len(t_checker *src);
int						tri_am_b(t_checker **src, t_checker **dest
		, int lensrc, int lendest);
int						tri_am_a(t_checker **src, t_checker **dest
		, int lensrc, int lendest);
int						fusion_recursiv(t_checker **src, t_checker **dest,
		int len, int s_d);
void					tridouble_extend(t_checker **dest, char a);
char						*tri_recursif(t_checker **a_list, t_checker **b_list, int len, int len_max);
int						is_trie(t_checker *a_list, t_checker *b_list);
int						recursif(t_checker **a_list, t_checker **b_list);


char	*push_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max);
char	*push_recursif_b(t_checker **a_list, t_checker **b_list, int len, int len_max);

char	*swap_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max);
char	*swap_recursif_b(t_checker **a_list, t_checker **b_list, int len, int len_max);

char	*rotate_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max);

char	*reverse_recursif_a(t_checker **a_list, t_checker **b_list, int len, int len_max);
#endif
