/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:11:06 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/16 04:31:55 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_x0(int tab[27][3], int x, int i)
{
	if (tab[i][0] == 1)
		return (tab[i][0]);
	return (tab[i][0] + x);
}

int		ft_check_x1(int tab[27][3], int x, int i)
{
	int n;

	n = 0;
	if (tab[i][0] != 1)
		n++;
	if ((tab[i][1] - tab[i][0]) == 1 && n == 0)
		return (tab[i][1]);
	if ((tab[i][1] - tab[i][0]) != 1)
		n++;
	return (tab[i][1] + (n * x));
}

int		ft_check_x2(int tab[27][3], int x, int i)
{
	int n;

	n = 0;
	if (tab[i][0] != 1)
		n++;
	if ((tab[i][1] - tab[i][0]) != 1)
		n++;
	if ((tab[i][2] - tab[i][1]) == 1 && n == 0)
		return (tab[i][2]);
	if ((tab[i][2] - tab[i][1]) != 1)
		n++;
	return (tab[i][2] + (n * x));
}

void	clean_tetra(char **map, int i)
{
	int j;

	j = 0;
	while ((*map)[j])
	{
		if ((*map)[j] == 'A' + i)
			(*map)[j] = '.';
		j++;
	}
}

int		ft_put_tetra(int pos, char **map, int tab_int[27][3], int i)
{
	int l;

	l = count_size(*map);
	if (tab_int[i][0] == 0)
		return (1);
	if ((*map)[pos] == '\0')
	{
		if (i != 0)
			return (0);
		ft_map(map);
		return (ft_put_tetra(0, map, tab_int, 0));
	}
	if (TAB0 == '.' && TAB1 == '.' && TAB2 == '.' && (*map)[pos] == '.')
	{
		(*map)[pos] = 'A' + i;
		TAB0 = 'A' + i;
		TAB1 = 'A' + i;
		TAB2 = 'A' + i;
		if (ft_put_tetra(0, map, tab_int, i + 1))
			return (1);
		clean_tetra(map, i);
	}
	return (ft_put_tetra(pos + 1, map, tab_int, i));
}
