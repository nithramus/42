/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:13:26 by bandre            #+#    #+#             */
/*   Updated: 2017/01/16 11:26:27 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>

typedef struct s_attrib
{
	int		rmaj;
	int		r;
	int		a;
	int		l;
	int		t;
	char	**list_fichier;
}			s_param;



s_param		*new_s_param(void);
s_param		*recup_param(char **list_param);
void		option_invalide(char *option, s_param *param);
void		go_to_dir(char *path, s_param *param);
void		afficher_error_malloc(void);
void		afficher_error_connais_pas(void);
void		free_s_param(s_param *param);
char		**tab_of_dir(char *path, s_param *param);
void		print_list_fichier(char *path, s_param *param);
char		*create_path(char *path, char *dir);
#endif
