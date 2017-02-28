/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 13:58:10 by bandre            #+#    #+#             */
/*   Updated: 2016/07/27 18:32:19 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct		s_struct
{
	char			*data;
	struct s_struct *next;
}					t_buff;

typedef struct		s_tadval
{
	int				right;
	int				down;
}					t_tabval;

t_buff				*ft_create_elem(char *data);
int					ft_strlen(char *c);
char				*ft_receive_tab(int *y, int fd, char *carac);
int					ft_count_column(char *chaine);
char				**copy_tab(char *buffer);
int					ft_count_line(char *chaine);
void				ft_putstr(char *c);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
t_tabval			**ft_creatabstruc(int x, int y);
t_tabval			**ft_remptab(int x, int y, char **str, char *carac);
int					ft_carepos(t_tabval **tab, int *x, int *y);
void				ft_printbsq(char **tab, int x, int y);
void				add_x(char **tab, int *pos, int size, char *carac);
void				ft_freetabstruc(t_tabval **str, int x);
void				ft_destroydd(char **tab);
void				ft_freechaine(t_buff *buffer);

#endif
