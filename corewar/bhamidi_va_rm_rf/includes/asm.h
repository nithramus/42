/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 08:45:40 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/09 13:42:24 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "../includes/op.h"
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# define LABEL		1
# define OPCODE		2
# define P_REG		31
# define P_IND		32
# define P_DIR		33
# define NAME		4
# define COMMENT	5

typedef struct			s_info
{
	char				*opcode;
	int					value;
}						t_info;

typedef struct			s_stable
{
	char				key;
	char				*value;
	int					label_pos;
	struct s_stable		*next;
	int					line;
}						t_stable;

char					get_opcode(t_stable *tab, int op);
int						ft_printf(const char *format, ...);
char					get_code_sti(t_stable *tab);
void					write_ind(char *value, int fd);

int						info_tab(t_stable *ptr);
void					write_dir(char *value, int fd, int op);
void					write_ind(char *value, int fd);
long long int			ft_spec_atoi(const char *str);
void					write_opcode(int op, t_stable *tab, int fd);
void					ft_putuchar_fd(unsigned char c, int fd);
void					write_infile(t_stable *tab, char *file_name);

char					get_code_axo(t_stable *tab);
void					increment_octet(t_stable *ptr);
int						get_oct(t_stable *ptr);
t_stable				*get_last(t_stable *tab);

int						get_op_tab(char *str);
int						is_label(char *str);
int						is_opcode(char *str);
int						is_param3(char *str);
int						is_param2(char *str);
int						is_param1(char *str);

int						free_string(char **str, int res);
int						info_tab(t_stable *ptr);
int						free_tab(char ***tab);
void					tab_push(t_stable **head, char key,
		char *value, int line);
int						get_occurs(char *str, char c);
int						fill_stable(char **tab, t_stable **head, char *str,
		int line);
char					**ft_split(char *s);
char					**ft_split_whitespaces(char *s);
int						lexical_parse(t_stable **head, int fd);
int						parsing(t_stable **head);
void					free_stable(t_stable **head);
int						count_tab(t_stable *ptr);
int						handle_line(char *str, char **tab);
int						count_basic_tab(char **tab);
char					**ft_white(char *str);
char					**ft_space(char *str);

void					put_option(t_stable *tab);
void					print_name_comment_error(void);
void					print_error_file(void);
void					print_syntax_error(t_stable **head,
		char *value, int line);
void					print_error_lexical(int row);
void					print_usage(char *path_exec);
void					print_stab(t_stable *ptr);
void					print_tab(int i, char **tab);
void					print_error_bad_file(t_stable **tab);

int						verif_nb_separator(int nb_s, char **tab, char *str);
void					free_str_head(t_stable **head, char **str);
void					free_str_tab(char **str, char ***tab);
void					free_str_tab_stab(char **str, char ***tab,
		t_stable **head);
int						clean_comment(char *str);
int						get_mem_value_where(char *label, t_stable *ptr);
int						get_modif_ind_value(char *op);
int						get_num(char *str);

int						test_ldi(t_stable **head);
int						test_aff(t_stable **head);
int						test_only_dir(t_stable **head);
int						test_add_sub(t_stable **head);
int						test_xor_or(t_stable **head);
int						test_load(t_stable **head);
int						test_st(t_stable **head);
int						test_sti(t_stable **head);

typedef struct			s_op
{
	char	*op_name;
	int		nb_param;
	char	code_param[3];
	int		op_code;
	int		nb_cycle;
	char	*op_comment;
	int		codage_octal;
	int		modif_ind;
}						t_op;

#endif
