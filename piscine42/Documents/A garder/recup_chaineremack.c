/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_chaineremack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 17:46:17 by bandre            #+#    #+#             */
/*   Updated: 2016/07/27 18:09:48 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_len_list(t_buff *begin)
{
	t_buff	*buff;
	int		len;

	len = 0;
	buff = begin;
	while (buff)
	{
		len += ft_strlen(buff->data);
		buff = buff->next;
	}
	return (len);
}

char	*ft_list_in_chaine(t_buff *begin)
{
	t_buff	*buff;
	int		len;
	char	*chaine;
	int		i;
	int		j;

	i = 0;
	len = ft_len_list(begin);
	chaine = malloc(len);
	buff = begin;
	while (buff)
	{
		j = 0;
		while (buff->data[j])
		{
			chaine[i] = buff->data[j];
			j++;
			i++;
		}
		buff = buff->next;
	}
	return (chaine);
}

void	ft_carac(char *chaine, char *carac)
{
	int i;

	i = 0;
	while (chaine[i] != '\n')
		i++;
	carac[0] = chaine[i - 3];
	carac[1] = chaine[i - 2];
	carac[2] = chaine[i - 1];
}

char	*ft_receive_tab(int *y, int fd, char *carac)
{
	char	str[25];
	t_buff	*buff;
	t_buff	*begin;
	char	*chaine;
	int		ret;

	buff = NULL;
	while (0 < (ret = read(fd, str, 24)))
	{
		str[ret] = '\0';
		if (buff == NULL)
		{
			buff = ft_create_elem(str);
			begin = buff;
		}
		else
		{
			buff->next = ft_create_elem(str);
			buff = buff->next;
		}
	}
	chaine = ft_list_in_chaine(begin);
	*y = ft_count_line(chaine);
	ft_carac(chaine, carac);
	return (chaine);
}

int		ft_verifchaine(char *chaine, char *car)
{
	int i;

	i = 1;
	while (chaine[i])
	{
		if (chaine[i] != car[0] || chaine[i] != car[1] || chaine[i] != car[2])
			return (0);
		i++;
	}
	return (1);
}
