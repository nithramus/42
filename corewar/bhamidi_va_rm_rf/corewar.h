/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:24:31 by bandre            #+#    #+#             */
/*   Updated: 2017/03/03 18:10:28 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

typedef struct			s_process
{
	char				registre[REG_NUMBER][REG_SIZE];
	int					live;
	char				carry;
	int					pc;
	unsigned char		op_code;
	int					act_cycle;
	int					cycle;
	char				color;
	struct s_process	*next;
	struct s_process	*previous;
}						t_process;

typedef struct			s_joueur
{
	char	num_joueur;
	int		nb_live;
	char	*name;
	char	*cri_de_guerre;
	int		last_live;
}						t_joueur;

typedef struct			s_op
{
	char	*op_name;
	int		nb_param;
	char	code_param[3];
	int		op_code;
	int		nb_cycle;
	char	*op_comment;
	int		codage_octal;
	int		jesaispas;
}						t_op;
