/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:43:15 by docioban          #+#    #+#             */
/*   Updated: 2017/12/18 12:12:34 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argv, char **argc)
{
	char	**fille;
	int		max_sqrt;
	char	**final;

	fille = NULL;
	if (argv < 2 || !(fille = ft_read(argc[1])))
	{
		ft_putendl("error");
		return (0);
	}
	if (check(fille) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	max_sqrt = ft_struct_make(fille);
	if (!(final = ft_algoritm(ft_sqrt_max(max_sqrt * 4), max_sqrt)))
	{
		ft_putendl("error");
		return (0);
	}
	ft_printarray(final);
}
