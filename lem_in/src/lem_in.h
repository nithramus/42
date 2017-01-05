/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:47:43 by bandre            #+#    #+#             */
/*   Updated: 2017/01/05 13:38:18 by bandre           ###   ########.fr       */
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

g_struct	**create_graph(void);
g_struct	*new_g_struct(char *name);
g_struct	**graphe_join(g_struct **src, g_struct *add);
g_struct	*graphchr(g_struct **list_salles, char *salles);
g_struct	**ptr_join(g_struct **list, g_struct *add);
g_struct	***find_path(g_struct *graphe);
#endif
