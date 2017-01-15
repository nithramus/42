/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:47:43 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 22:15:56 by bandre           ###   ########.fr       */
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
	int				nb_fourmis;
}					f_path;

typedef struct		fourmis_path
{
	int				pos;
	f_path			*road;
	int				num_fourmis;
	int				move;
}					s_fourmis;

int		afficher(g_struct **list_salles);
int		afficher_road(f_path **road);

g_struct	**create_graph(g_struct **start, g_struct **end);
g_struct	*new_g_struct(char *name);
g_struct	**graphe_join(g_struct **src, g_struct *add);
g_struct	*graphchr(g_struct **list_salles, char *salles);
g_struct	**ptr_join(g_struct **list, g_struct *add);
g_struct	**ptr_join_not_free(g_struct **list, g_struct *add);
s_fourmis	**s_fourmis_join(s_fourmis **list, s_fourmis *newelem);
f_path		**find_path(g_struct *start, g_struct *end);
f_path		**path_join(f_path ***list, g_struct **add);
f_path		*new_f_path(g_struct **add);
s_fourmis	*new_fourmis(f_path *road, int num_fourmis);
void		path_combinaison(f_path **a_path, f_path ***dependance, f_path **ac_path, int nb_path, int nb_max, int nb_fourmis);

int			test_nbtour(f_path **act_path, int nb_fourmis);
int			make_dependance(f_path **path);
int			is_in_list(g_struct **list_salles, g_struct *salle);
int			fourmis_chemins(f_path **best_path, int nb_fourmis);

void		afficher_error(void);
void		ft_free_list_g_struct(g_struct **list_ptr);
void		ft_free_list_f_path(f_path **list_ptr);
void		ft_free_split(char **str);
void		ft_free_s_fourmis(s_fourmis **list);
#endif
