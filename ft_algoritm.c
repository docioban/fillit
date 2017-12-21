/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:27:48 by docioban          #+#    #+#             */
/*   Updated: 2017/12/18 16:11:48 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	punere(char **tab, int i, int y, int x)
{
	char	c;

	c = s[i].letter;
	tab[y + s[i].y[0]][x + s[i].x[0]] = c;
	tab[y + s[i].y[1]][x + s[i].x[1]] = c;
	tab[y + s[i].y[2]][x + s[i].x[2]] = c;
	tab[y + s[i].y[3]][x + s[i].x[3]] = c;
}

int		verific(char **tab, int i, int y, int x)
{
	if (tab[y + s[i].y[0]][x + s[i].x[0]] == '.')
		if (tab[y + s[i].y[1]][x + s[i].x[1]] == '.')
			if (tab[y + s[i].y[2]][x + s[i].x[2]] == '.')
				if (tab[y + s[i].y[3]][x + s[i].x[3]] == '.')
				{
					punere(tab, i, y, x);
					return (1);
				}
	return (0);
}

void	restabilire(char **tab, int y)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = s[y].letter;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

char	**algoritm(char **new, int sqrt_max, int i, int n)
{
	int			x;
	int			y;
	char		**tab;

	y = 0;
	if (i == n)
		return (new);
	tab = NULL;
	while (y < sqrt_max - s[i].y[3] - s[i].y[0])
	{
		x = 0;
		while (x < sqrt_max)
		{
			if (verific(new, i, y, x))
			{
				if (!(tab = algoritm(new, sqrt_max, i + 1, n)))
					restabilire(new, i);
				if (tab)
					return (tab);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

char	**ft_algoritm(int sqrt_max, int n)
{
	char	**new;

	new = new_tab(sqrt_max);
	new = algoritm(new, sqrt_max, 0, n);
	while (!new)
	{
		sqrt_max++;
		new = new_tab(sqrt_max);
		new = algoritm(new, sqrt_max, 0, n);
	}
	return (new);
}
