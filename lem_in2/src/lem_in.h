/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:47:43 by bandre            #+#    #+#             */
/*   Updated: 2017/02/13 20:57:20 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/ft_printf/ft_printf.h"

typedef struct		s_graphe
{
	char			*name;
	struct s_graphe	**liaisons;
}					t_struct;

typedef struct		s_path
{
	struct s_path	**dependance;
	t_struct		**path;
	int				nb_fourmis;
}					t_path;

typedef struct		s_fourmis_path
{
	int				pos;
	t_path			*road;
	int				num_fourmis;
	int				move;
}					t_fourmis;

int					afficher(t_struct **list_salles);
int					afficher_road(t_path **road);

t_struct			**create_graph(t_struct **start, t_struct **end,
		char **fichier);
t_struct			*new_t_struct(char *name);
t_struct			**graphe_join(t_struct **src, t_struct *add);
t_struct			*graphchr(t_struct **list_salles, char *salles);
t_struct			**ptr_join(t_struct **list, t_struct *add);
t_struct			**ptr_join_not_free(t_struct **list, t_struct *add);
t_fourmis			**t_fourmis_join(t_fourmis **list, t_fourmis *newelem);
t_path				**find_path(t_struct *start, t_struct *end);
t_path				**path_join(t_path ***list, t_struct **add);
t_path				*new_t_path(t_struct **add);
t_fourmis			*new_fourmis(t_path *road, int num_fourmis);
void				path_combinaison(t_path **a_path, t_path ***dependance,
		t_path **ac_path, int tab[3]);

int					test_nbtour(t_path **act_path, int nb_fourmis);
int					make_dependance(t_path **path);
int					is_in_list(t_struct **list_salles, t_struct *salle);
int					fourmis_chemins(t_path **best_path, int nb_fourmis);

void				afficher_error(void);
void				ft_free_list_t_struct(t_struct **list_ptr);
void				ft_free_list_t_path(t_path **list_ptr);
void				ft_free_split(char **str);
void				ft_free_t_fourmis(t_fourmis **list);
int					ft_is_number(int *fourmis, char **ficheir);
int					fichier_comp(char **fichier, char *str);
void				afficher_error_path(t_path **path, t_struct **graph,
		char *fichier);
int					test_valide(char **split, char *line);
int					test_error(char **split, char *line);
void				ft_free(char **split, char *line);
#endif
