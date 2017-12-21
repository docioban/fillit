/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:23:18 by docioban          #+#    #+#             */
/*   Updated: 2017/12/14 19:30:54 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_tab(int sqrt_max)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (sqrt_max + 1));
	while (i < sqrt_max)
	{
		j = 0;
		new[i] = (char *)malloc(sizeof(char) * (sqrt_max * 2));
		while (j < sqrt_max)
		{
			new[i][j] = '.';
			j++;
		}
		new[i][j] = '\n';
		new[i][j + 1] = '\0';
		i++;
	}
	new[i] = 0;
	return (new);
}
