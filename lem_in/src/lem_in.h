/* ************************************************************************** */
	char			**name;
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:47:43 by bandre            #+#    #+#             */
/*   Updated: 2017/01/06 00:02:00 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/ft_printf/ft_printf.h"

typedef struct		s_graphe
{
	char			*name;
	struct s_graphe	**liaisons;
}					g_struct;

typedef struct		s_path
{
	struct s_path	**dependance;
	g_struct		**path;
}					f_path;

int		afficher(g_struct **list_salles);


g_struct	**create_graph(g_struct **start, g_struct **end);
g_struct	*new_g_struct(char *name);
g_struct	**graphe_join(g_struct **src, g_struct *add);
g_struct	*graphchr(g_struct **list_salles, char *salles);
g_struct	**ptr_join(g_struct **list, g_struct *add);
f_path		**find_path(g_struct *start, g_struct *end);
f_path		**path_join(f_path ***list, g_struct **add);
f_path		*new_f_path(g_struct **add);
f_path		**path_combinaison(f_path **a_path, f_path ***dependance, f_path **ac_path, int nb_path, int nb_max);

int			test_nbtour(f_path **act_path, int nb_fourmis);
int			make_dependance(f_path **path);
int			is_in_list(g_struct **list_salles, g_struct *salle);

#endif
