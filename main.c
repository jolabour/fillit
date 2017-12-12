/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:51:03 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/12 06:20:51 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_map(int l, char *map)
{
	int i;
	int n;
	char *new_map;

	n = 1;
	i = 0;
	free(map);
	if (!(new_map = (char *)malloc(sizeof(char) * (((l + 1) * l) + 1))))
		return (NULL);
	while (i < ((l + 1) * l))
	{
		if (i + 1 == ((((l + 1) * l) / l) * n))
		{
			new_map[i] = '\n';
			n++;
		}
		else
			new_map[i] = '.';
		i++;
	}
	new_map[i] = '\0';
	return (new_map);
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

int		ft_put_tetra(int pos, int l, int x, char *map, int **tab_int, int i)
{
	int j;
	j = 0;
	if (tab_int[i] == 0)
		return (1);
	if (map[pos] == '\0' && i == 0)
		return (ft_put_tetra(0, l + 1, x + 1, ft_map(l + 1, map), tab_int, 0));
	//ft_putendl(map);
	if (map[pos] == '\0')
	{
		//ft_putendl("mdr");
		return (0);
	}
	if (map[pos] != '.')
		return (ft_put_tetra(pos + 1, l, x, map, tab_int, i));
	map[pos] = 'A' + i;
	while (map[pos])
	{
		if (map[pos + (ft_check_x0(tab_int, x, i))] == '.' && map[pos + (ft_check_x1(tab_int, x, i))] == '.' && map[pos + (ft_check_x2(tab_int, x, i))] == '.')
		{
			map[pos + (ft_check_x0(tab_int, x, i))] = 'A' + i;
			//ft_putnbr(ft_check_x0(tab_int, x, i));
			map[pos + (ft_check_x1(tab_int, x, i))] = 'A' + i;
			//ft_putnbr(ft_check_x1(tab_int, x, i));
			map[pos + (ft_check_x2(tab_int, x, i))] = 'A' + i;
			//ft_putnbr(i);
				if (ft_put_tetra(0 , l, x, map, tab_int, i + 1))
					return (1);
		}
		map[pos] = '.';
		j = 0;
		while (map[j])
		{
			if (map[j] == 'A' + i)
				map[j] = '.';
			j++;
		}
		return (ft_put_tetra(pos + 1, l, x, map, tab_int, i));
	}
	return (0);
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
	a = 4;
	x = 0;
	map = ft_map(a, map);
	tab = ft_check(argc, argv);
	/*z = 0;
	i = 0;
	while (tab[z] != 0)
	{
		a = 0;
		while (a < 3)
		{
	//ft_putnbr(j);
			ft_putnbr(tab[z][a]);
			ft_putchar('\n');
			a++;
		}
		ft_putchar('\n');
		z++;
	}*/
	//ft_putendl(map);
	ft_put_tetra(pos, a, x, map, tab, i);
	ft_putstr(map);
	//ft_putstr(ft_map(a));
	return (0);
}
