/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:57:34 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/16 04:55:57 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_check_validity(char *str, int n)
{
	int				i;
	unsigned int	points;
	unsigned int	hash;

	hash = 0;
	points = 0;
	i = 0;
	while (str[i])
	{
		if ((str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19]
			!= '\n') || (n != 1 && str[20] != '\n') || (hash > 4 || points >
			12) || (str[i] != '#' && str[i] != '.' && str[i] != '\n'))
			return (0);
		if (str[i] == '.')
			points++;
		if (str[i] == '#')
			hash++;
		if (n == 1)
		{
			if (str[20] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int					ft_check_tetra(char *str, const int g_tab[19][3])
{
	int				x;
	int				j;

	x = 0;
	j = 0;
	while (str[x] != '#' && str[x])
		x++;
	while (j < 19)
	{
		if (str[x + g_tab[j][0]] == '#' && str[x + g_tab[j][1]] == '#' && str[x
				+ g_tab[j][2]] == '#')
			return (1);
		j++;
	}
	return (0);
}
