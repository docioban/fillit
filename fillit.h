/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:43:39 by docioban          #+#    #+#             */
/*   Updated: 2017/12/14 20:03:20 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_struct
{
	char		*str;
	char		letter;
	int			x[4];
	int			y[4];
}				t_struct;

struct s_struct s[26];
char			**ft_read(char *file);
int				check(char **tab);
void			ft_printarray(char **array);
int				ft_struct_make(char **tab);
char			**ft_algoritm(int sqrt_max, int n);
char			**new_tab(int sqrt_max);

#endif
