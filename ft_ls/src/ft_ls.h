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



void		free_s_param(s_param *param);
#endif
