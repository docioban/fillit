/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:15:27 by docioban          #+#    #+#             */
/*   Updated: 2017/12/20 15:33:24 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nr_line(char *buf)
{
	int i;
	int nr;

	i = 0;
	nr = 0;
	while (buf[i] != '\0')
	{
		i++;
		if (buf[i] == '\n' && (buf[i - 1] == '\n' || buf[i + 1] == '\0'))
			nr++;
		if ((buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0')) &&
				(buf[i - 1] != '.' && buf[i - 1] != '#'))
			return (0);
	}
	return (nr);
}

char	*ft_strprint_fillit(char *buf, int index)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)malloc(21);
	if (index != 0)
		index++;
	while (i < 20)
	{
		tab[i] = buf[index];
		i++;
		index++;
	}
	if (buf[index] != '\0' && buf[index] != '\n')
		return (NULL);
	tab[i] = '\0';
	return (tab);
}

char	**ft_strsplit_fillit(char *buf)
{
	int		i;
	int		j;
	char	**tab;
	int		nr_line;

	i = 0;
	j = 0;
	if ((nr_line = ft_nr_line(buf)) == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char **) * (nr_line + 1));
	while (buf[i] != '\0')
	{
		if (i == 0 || (buf[i] == '\n' && buf[i - 1] == '\n'))
		{
			if (!(tab[j] = ft_strprint_fillit(buf, i)))
				return (NULL);
			j++;
		}
		i++;
	}
	if (buf[i - 2] != '.' && buf[i - 2] != '#')
		return (0);
	tab[nr_line] = 0;
	return (tab);
}

char	**ft_read(char *file)
{
	int		op;
	size_t	rd;
	char	*buf;
	char	**tab;

	buf = (char *)malloc(546);
	if ((op = open(file, O_RDONLY)) == 0)
		return (NULL);
	if ((rd = read(op, buf, 545)) == 0)
		return (NULL);
	close(op);
	if (!(tab = ft_strsplit_fillit(buf)))
		return (NULL);
	return (tab);
}
