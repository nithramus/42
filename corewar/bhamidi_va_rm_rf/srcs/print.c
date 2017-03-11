/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:11:19 by bhamidi           #+#    #+#             */
/*   Updated: 2017/03/08 15:43:09 by bhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_name_comment_error(void)
{
	ft_putendl("error in name or comment or no instruction");
	exit(EXIT_FAILURE);
}

void	print_usage(char *path_exec)
{
	ft_putstr("Usage: ");
	ft_putstr(path_exec);
	ft_putendl(" [-a] <sourcefile.s>");
	ft_putstr("\t-a : Instead of creating a .cor file, outputs a stripped ");
	ft_putendl("and annotated version of the code to the standard output");
	exit(EXIT_FAILURE);
}

void	print_syntax_error(t_stable **head, char *value, int line)
{
	ft_putstr("syntax error at line ");
	ft_putnbr(line);
	ft_putstr(": [");
	ft_putstr(value);
	ft_putstr("]\n");
	free_stable(head);
	exit(EXIT_FAILURE);
}

void	print_error_lexical(int row)
{
	ft_putstr("lexical error at line: ");
	ft_putnbr(row);
	exit(EXIT_FAILURE);
}

void	print_error_file(void)
{
	ft_putendl("Error input file");
	exit(EXIT_FAILURE);
}
