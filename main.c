/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:51:03 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/10 09:44:12 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_map(int l)
{
	char *map;
	int i;
	int n;

	n = 1;
	i = 0;
	if (!(map = (char *)malloc(sizeof(char) * (((l + 1) * l) + 1))))
		return (NULL);
	while (i < ((l + 1) * l))
	{
		if (i + 1 == ((((l + 1) * l) / l) * n))
		{
			map[i] = '\n';
			n++;
		}
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

int		ft_put_tetra(int pos, int l, int x, char *map, int **tab_int)
{
	int i;

	i = 0;
	if (tab_int[i] == 0)
		return (1);
	if (map[pos] == '\0')
	{
		free(map);
		return (ft_put_tetra(0, l + 1, x + 1, ft_map(l), tab_int));
	}
	a = 0;
	map[pos] = 'A' + i;
	if (map[pos + (tab_int[i][0] + x)] == '.' && map[pos + (tab_int[i][1] + x)] == '.' && map[pos + (tab_int[i][2] + x)] == '.')
	{
		map[pos + (tab_int[i][0] + x)] = 'A' + i;
		map[pos + (tab_int[i][1] + x)] = 'A' + i;
		map[pos + (tab_int[i][2] + x)] = 'A' + i;







int		main(int argc, char **argv)
{
	int **tab;
	int z;
	int a;

	a = 2;
	x = -2;
	tab = ft_check(argc, argv);
	ft_putstr(ft_map(a));
	/*z = 0;
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
	return (0);
}


