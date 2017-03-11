/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:44:49 by msrun             #+#    #+#             */
/*   Updated: 2017/03/09 14:00:36 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_asm.h"

char	*change_name(char *name)
{
	int		i;
	char	*new_name;

	if (!(new_name = malloc(sizeof(char) * (ft_strlen(name) + 1))))
		return (0);
	i = -1;
	while (name[++i])
		new_name[i] = name[i];
	new_name[i] = 0;
	i = ft_strlen(name);
	new_name[i - 3] = 's';
	new_name[i - 2] = 0;
	return (new_name);
}

int		ft_fill_file_with_str(int fd, unsigned char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len && str[i])
		write(fd, &str[i], 1);
	return (0);
}

int		fill_name_comment(int fd_f, int fd_n, unsigned char *str)
{
	if (read(fd_f, str, 4) == -1)
		return (1);
	if (read(fd_f, str, 128) != 128)
		return (1);
	str[128] = 0;
	write(fd_n, ".name\t\t\"", 8);
	ft_fill_file_with_str(fd_n, str, 128);
	write(fd_n, "\"\n", 2);
	if (read(fd_f, str, 8) == -1)
		return (1);
	if (read(fd_f, str, 2048) != 2048)
		return (1);
	str[2048] = 0;
	write(fd_n, ".comment\t\"", 10);
	ft_fill_file_with_str(fd_n, str, 2048);
	write(fd_n, "\"\n", 2);
	if (read(fd_f, str, 4) == -1)
		return (1);
	return (0);
}

int		fill_file(int fd_f, int fd_n)
{
	unsigned char	*str;
	int				ret;

	if (!(str = malloc(sizeof(char) * (COMMENT_LENGTH + 1))))
		return (write(1, "Error memory\n", 13));
	if (fill_name_comment(fd_f, fd_n, str))
		return (write(1, "Error file\n", 11));
	if ((ret = read(fd_f, str, 700)) == -1)
		return (write(1, "Error file\n", 11));
	str[ret] = 0;
	fill_ops(str, fd_n, ret);
	free(str);
	return (0);
}

int		main(int ac, char *av[])
{
	int		fd_n;
	int		fd_f;
	char	*new_name;

	if (ac != 2)
		return (write(1, "Usage : des [file_name]\n", 24));
	if (ft_strcmp(av[1] + (ft_strlen(av[1]) - 4), ".cor"))
		return (write(1, "Wrong file type\n", 16));
	if (!(new_name = change_name(av[1])))
		return (write(1, "Error memory\n", 13));
	if ((fd_n = open(new_name, O_RDWR | O_CREAT | O_TRUNC, 0600)) == -1)
		return (write(1, "Error open\n", 11));
	if ((fd_f = open(av[1], O_RDONLY)) == -1)
		return (0);
	fill_file(fd_f, fd_n);
	close(fd_n);
	close(fd_f);
	free(new_name);
	return (0);
}
