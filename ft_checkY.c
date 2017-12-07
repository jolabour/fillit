/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 01:43:50 by ymarcill          #+#    #+#             */
/*   Updated: 2017/12/07 10:07:45 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int tab[19][3] =
{
	{5,6,10},
	{4,5,10},
	{1,2,6},
	{4,5,6},
	{5,10,11},
	{5,9,10},
	{1,2,5},
	{1,2,7},
	{1,5,10},
	{1,6,11},
	{5,6,11},
	{4,5,9},
	{1,6,7},
	{1,4,5},
	{1,5,6},
	{5,10,15},
	{1,2,3},
	{5,6,7},
	{3,4,5},
};

int		ft_check_validity(char *str, int n)
{
	int i;
	unsigned int points;
	unsigned int hash;

	hash = 0;
	points = 0;
	i = 0;
	while (str[i])
	{
		if (str[0] != '#' && str[0] != '.')
			return (0);
		if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != 
				'\n')
			return (0);
		if (str[i] == '.')
			points++;
		if (str[i] == '#')
			hash++;
		if (hash > 4 || points > 12)
			return (0);
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (n == 1)
		{
			if (str[20] != '\0')
				return (0);
		}
		i++;
	}
	if (str[20] == '\n' && str[21] != '\0')
		return (0);
	return (1);
}

int		ft_check_tetra(char *str, const int tab[19][3])
{
	int x;
	int j;

	x = 0;
	j = 0;
	while (str[x] != '#' && str[x])
		x++;
	while (j < 19)
	{
		if (str[x + tab[j][0]] == '#' && str[x + tab[j][1]] == '#' && str[x + tab[j][2]] =='#')
			return (1);
		j++;
	}
	return (0);
}

int		ft_stock_tetra(char *str, int tab[19][3])
{
	int x;
	int j;

	x = 0;
	j = 0;
	while (str[x] != '#' && str[x])
		x++;
	while (j < 19)
	{
		if (str[x + tab[j][0]] == '#' && str[x + tab[j][1]] == '#' && str[x + tab[j][2]] == '#')
			return (j);
		j++;
	}
	return (0);
}

int		ft_check(int argc, char **argv)
{
	int i;
	char buf[BUF_SIZE + 1];
	int fd;
	int x;
	int n;
	int **tab_int;
	int j;
	int a;
	int z;

	j = 0;
	x = 0;
	n = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if (argc != 2)
		ft_putendl("usage: ./fillit target_file");
	else
	{
		while ((i = read(fd, buf, BUF_SIZE)) > 0)
			n++;
		i = 0;
		if (!(tab_int = (int **)malloc(sizeof(int *) * n )))
			return (0);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		while ((i = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[i] = '\0';
			if (!ft_check_validity(buf, n) || !ft_check_tetra(buf, tab))
				return (0);
			tab_int[j] = (int *)malloc(sizeof(int) * 3);
			a = 0;
			while (a < 3)
			{
				tab_int[j][a] = tab[ft_stock_tetra(buf, tab)][a];
				a++;
			}
			n--;
			j++;
		}
	}
	z = 0;
	while (z < j)
	{
		a = 0;
		while (a < 3)
		{
	//ft_putnbr(j);
			ft_putnbr(tab_int[z][a]);
			ft_putchar('\n');
			a++;
		}
		ft_putchar('\n');
		z++;
	}
	if (close(fd) == -1)
		ft_putendl("error");
	return (1);
}

int		main(int argc, char **argv)
{
	ft_check(argc, argv);
	return (0);
		ft_putendl("usage: ./fillit target_file");
}
