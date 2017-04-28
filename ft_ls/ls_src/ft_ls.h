/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:45:35 by bandre            #+#    #+#             */
/*   Updated: 2017/04/28 20:08:06 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "../libft/libft/libft.h"
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>



typedef struct	s_option
{
	int			r;
	int			rmaj;
	int			a;
	int			l;
	int			t;
}				t_option;


void	quit_clean(int error);
int			get_option(int argc, char **argv, t_option *option);
void	printf_option(t_option option);
int		path_mov(char *path, t_option option);

#endif
