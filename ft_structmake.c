/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structmake.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:01:39 by docioban          #+#    #+#             */
/*   Updated: 2017/12/20 15:33:48 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_swap_top(char *tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_swap_char(&tab[i], &tab[i + 1]);
		ft_swap_char(&tab[i + 5], &tab[i + 6]);
		ft_swap_char(&tab[i + 10], &tab[i + 11]);
		ft_swap_char(&tab[i + 15], &tab[i + 16]);
		i++;
	}
}

void	muta(char *tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < x)
	{
		ft_swap_top(tab);
		j++;
	}
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < 4)
		{
			ft_swap_char(&tab[i], &tab[i + 5]);
			ft_swap_char(&tab[i + 5], &tab[i + 10]);
			ft_swap_char(&tab[i + 10], &tab[i + 15]);
			i++;
		}
		j++;
	}
}

void	ft_aranjare(char *tab)
{
	int x;
	int y;

	x = 0;
	while (tab[x] != '#' && tab[x + 5] != '#' &&
			tab[x + 10] != '#' && tab[x + 15] != '#')
		x++;
	y = 0;
	while (tab[y] != '#')
		y++;
	y = y / 5;
	muta(tab, x, y);
}

void	ft_struct_coordonate(char **tab)
{
	int			i;
	int			j;
	int			nr;

	i = 0;
	while (tab[i])
	{
		j = 0;
		nr = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
			{
				s[i].x[nr] = j % 5;
				s[i].y[nr] = j / 5;
				nr++;
			}
			j++;
		}
		i++;
	}
}

int		ft_struct_make(char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		ft_aranjare(tab[i]);
		s[i].str = tab[i];
		s[i].letter = i + 'A';
		i++;
	}
	ft_struct_coordonate(tab);
	return (i);
}
