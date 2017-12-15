/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:51:03 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/15 03:06:12 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map(int l, char **map)
{
	int i;
	int n;

	n = 1;
	i = 0;
	//free(map);
	if (!(*map = (char *)malloc(sizeof(char) * (((l * l) + l) + 1))))
		return ;
	while (i < ((l + 1) * l))
	{
		if (i + 1 == ((((l + 1) * l) / l) * n))
		{
			(*map)[i] = '\n';
			n++;
		}
		else
			(*map)[i] = '.';
		i++;
	}
	(*map)[i] = '\0';
	//ft_putstr(map);
}

int		ft_check_x0(int **tab, int x, int i)
{
	if (tab[i][0] == 1)
		return (tab[i][0]);
	return (tab[i][0] + x);
}

int		ft_check_x1(int **tab, int x, int i)
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

int		ft_check_x2(int **tab, int x, int i)
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

int		ft_put_tetra(int pos, int l, int x, char **map, int **tab_int, int i)
{
	int j;

	if (tab_int[i] == 0)
		return (1);
	if ((*map)[pos] == '\0')
	{
		if (i != 0)
			return (0);
		l++;
		free(*map);
		ft_map(l, map);
		return (ft_put_tetra(0, l, x + 1, map, tab_int, 0));
	}
	if ((*map)[pos + (ft_check_x0(tab_int, x, i))] == '.' && (*map)[pos + (ft_check_x1(tab_int, x, i))] == '.' && (*map)[pos + (ft_check_x2(tab_int, x, i))] == '.' && (*map)[pos] == '.')
	{
		(*map)[pos] = 'A' + i;
		(*map)[pos + (ft_check_x0(tab_int, x, i))] = 'A' + i;
		(*map)[pos + (ft_check_x1(tab_int, x, i))] = 'A' + i;
		(*map)[pos + (ft_check_x2(tab_int, x, i))] = 'A' + i;
		if (ft_put_tetra(0 , l, x, map, tab_int, i + 1))
			return (1);
		(*map)[pos] = '.';
		j = 0;
		while ((*map)[j])
		{
			if ((*map)[j] == 'A' + i)
				(*map)[j] = '.';
			j++;
		}
	}
	return (ft_put_tetra(pos + 1, l, x, map, tab_int, i));
}

	int		main(int argc, char **argv)
	{
		char *map;
		int **tab;
		int z;
		int a;
		int x;
		int pos;
		int i;

		pos = 0;
		a = 2;
		x = -2;
		i = 0;
		map = NULL;
		if (!(ft_check(argc, argv)))
			exit(argc);
		ft_map(a, &map);
		tab = ft_check(argc, argv);
		ft_put_tetra(pos, a, x, &map, tab, i);
		ft_putstr(map);
		return (0);
	}
