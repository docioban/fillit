/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:40:48 by docioban          #+#    #+#             */
/*   Updated: 2017/12/14 08:10:30 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_simbols(char **tab, int i, int j, int simbol)
{
	int point;
	int endl;

	while (tab[++i])
	{
		j = 0;
		simbol = 0;
		point = 0;
		endl = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
				simbol++;
			else if (tab[i][j] == '.')
				point++;
			else if (tab[i][j] == '\n')
				endl++;
			else
				return (0);
			j++;
		}
		if (simbol != 4 || point != 12 || endl != 4)
			return (0);
	}
	return (1);
}

int		check_figura_bottom(char **tab, int i, int j)
{
	if (tab[i][j + 1] == '#')
		return (1);
	return (0);
}

int		check_figura(char **tab, int i, int j)
{
	if (tab[i][j + 1] == '#' && tab[i][j + 5] == '#')
		return (2);
	else if (tab[i][j + 1] == '#' || tab[i][j + 5] == '#')
		return (1);
	return (0);
}

int		check_figuri(char **tab)
{
	int i;
	int j;
	int nr;

	i = 0;
	while (tab[i])
	{
		j = 0;
		nr = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
			{
				if (j > 14 && j < 19)
					nr += check_figura_bottom(tab, i, j);
				else
					nr += check_figura(tab, i, j);
			}
			j++;
		}
		if (nr < 3)
			return (0);
		i++;
	}
	return (1);
}

int		check(char **tab)
{
	if (check_simbols(tab, -1, 0, 0) == 0)
		return (0);
	if (check_figuri(tab) == 0)
		return (0);
	return (1);
}
