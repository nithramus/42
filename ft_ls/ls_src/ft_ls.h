/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:45:35 by bandre            #+#    #+#             */
/*   Updated: 2017/05/15 14:11:03 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "../libft/libft/libft.h"
#include <errno.h>
#include <dirent.h>
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


typedef struct	s_file
{
	char		*file;
	struct stat 	info;
	struct s_file	*next;
}				t_file;

void	quit_clean(int error);
int			get_option(int argc, char **argv, t_option *option);
void	printf_option(t_option option);
int		path_mov(char stock[4097], t_option option, int ptr);
int		ft_sort(t_file **mem_ptr, t_option option);

void	print_list(t_file *first);
void		show_dir(t_file *first, char stock[4097], int ptr);

#endif
