/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:12:32 by bhamidi           #+#    #+#             */
/*   Updated: 2016/12/10 23:30:43 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_info
{
	char			*att;
	int				f_larger;
	int				pre;
	char			*m_longer;
	char			conv;
}					t_info;

char				*parse_last1(char *str, t_info *info);
char				*add_putwchar(wchar_t w, char *n);
void				more_parse_last(t_info *info, char *str, int n, size_t l);
char				*dispatch_parse(char *str, t_info *i, size_t l);
char				*parse_double(char *str, size_t l, t_info *info, char *s);
char				*parse_sq(char *str, t_info *info, int n, size_t len_init);
char				*parse_spec(char *str, t_info *info);
char				*parse_sp_plus(t_info *info, char *str);
char				*parse_pre(t_info *info, char *str);
char				*ft_get_char(char *b, char *n, int l);
void				ft_more_pointer(char *str, int *len);
void				char_config(char *str, t_info *info, int *len);
void				print_uu(va_list ap, t_info *info, int *len);
char				*ft_uitoa(long long int n, int base);
void				print_uint(va_list ap, t_info *info, int *len);
char				*ft_strnew(size_t size);
char				*parse_ui(size_t arg, t_info *info);
void				ft_config_larger(char *tmp, char *str, int larger);
char				*ft_fill_champ(char *att, char *str, int larger);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memset(void *b, int c, size_t len);
int					ft_atoi_bin(const char *str);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*parse_string(int larger, char *att, int pre, char *arg);
char				*ft_putwchar(wchar_t w);
void				print_strwchar(va_list ap, t_info *info, int *len);
char				*print_ww(wchar_t arg);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strrev(char *src);
char				*ft_itoa_base(size_t n, size_t base);
void				print_wchar(va_list ap, t_info *info, int *len);
void				ft_get_nb_octet(int *nb, int *is_neg, long long int n);
void				ft_get_nb_u_octet(int *nb, int *is, long long int n);
void				print_sc(va_list ap, t_info *info, int *len);
void				print_lli(va_list ap, t_info *info, int *len);
void				print_si(va_list ap, t_info *info, int *len);
void				print_size_t(va_list ap, t_info *info, int *len);
void				print_li(va_list ap, t_info *info, int *len);
void				print_ui(va_list ap, t_info *info, int *len);
void				print_uc(va_list ap, t_info *info, int *len);
void				ft_int_parsing(t_info *info, char *str, int *len);
void				print_usi(va_list ap, t_info *info, int *len);
void				print_uli(va_list ap, t_info *info, int *len);
void				print_ulli(va_list ap, t_info *info, int *len);
void				print_char(va_list ap, t_info *info, int *len);
void				print_percent(int pre, int f_larger, char *att, int *len);
void				print_string(va_list ap, t_info *info, int *len);
void				print_pointer(t_info *info, va_list ap, int *p);
void				print_int(va_list ap, t_info *info, int *len);
void				brute_u_int(t_info *info, va_list ap, int *len);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_itoa(long long int n);
void				brute_int(t_info *info, va_list ap, int *len);
void				ft_put_hexa_nbr(unsigned int nb);
void				print_arg(t_info *info, va_list ap, int *len);
void				ft_strdel(char **str);
int					ft_atoi(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				fill_info(const char *s, t_info **info);
t_info				*info_init(t_info *info);
char				*ft_strdup(const char *str);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(const char *str);
int					ft_printf(const char *format, ...);
size_t				ft_strlen(const char *str);
void				ft_putnbr_ull(size_t nb);
void				ft_putnbr_ll(long long int nb);
int					ft_toupper(int c);

#endif
