/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:02:53 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/19 10:11:22 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	g_tab[19][3] = {{5, 6, 10}, {4, 5, 10}, {1, 2, 6}, {4, 5, 6},
	{5, 10, 11}, {5, 9, 10}, {1, 2, 5}, {1, 2, 7}, {1, 5, 10}, {1, 6, 11},
	{5, 6, 11}, {4, 5, 9}, {1, 6, 7}, {1, 4, 5}, {1, 5, 6}, {5, 10, 15},
	{1, 2, 3}, {5, 6, 7}, {3, 4, 5}};

int			ft_stock_tetra(char *str, const int g_tab[19][3])
{
	int		x;
	int		j;

	x = 0;
	j = 0;
	while (str[x] != '#' && str[x])
		x++;
	while (j < 19)
	{
		if (str[x + g_tab[j][0]] == '#' && str[x + g_tab[j][1]] == '#'
				&& str[x + g_tab[j][2]] == '#')
			return (j);
		j++;
	}
	return (0);
}

int			ft_count_tetra(char **argv, char *buf)
{
	int		fd;
	int		i;
	int		n;

	n = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while ((i = read(fd, buf, BUF_SIZE)) > 0)
		n++;
	if (close(fd) == -1)
		return (0);
	return (n);
}

int			*ft_stock_tab(char *buf, int tab_int[27][3], int j)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		tab_int[j][i] = g_tab[ft_stock_tetra(buf, g_tab)][i];
		i++;
	}
	return (g_tab[j]);
}

int			ft_check(char **argv, int tab_int[27][3])
{
	int		i;
	char	buf[BUF_SIZE + 1];
	int		j;
	int		fd;
	int		n;

	n = ft_count_tetra(argv, buf);
	j = 0;
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while ((i = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (!ft_check_validity(buf, n) || !ft_check_tetra(buf, g_tab) || n == 0)
			return (0);
		ft_stock_tab(buf, tab_int, j);
		n--;
		j++;
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}
