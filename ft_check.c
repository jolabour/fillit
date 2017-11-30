/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 00:33:07 by ymarcill          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/30 00:56:46 by ymarcill         ###   ########.fr       */
=======
/*   Updated: 2017/11/27 04:27:15 by jolabour         ###   ########.fr       */
>>>>>>> d1f94e42c9a3f5c1cea9bca01248c1886bd32287
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
<<<<<<< HEAD
#include <stdio.h>
int		ft_checkvalidity(char *str)
=======
#include <fcntl.h>

int		test(char **argv)
{
	int i;
	char buf[BUF_SIZE + 1];
	int fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((i = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[i] = '\0';
		ft_putstr(buf);
		if (!ft_check_validity(buf) || !ft_check_tetra(buf))
			return (0);
	}
	if (close(fd) == -1)
		return (-1);
	return (1);
}

int		ft_check_validity(char *str)
>>>>>>> d1f94e42c9a3f5c1cea9bca01248c1886bd32287
{
	int i;
	unsigned int points;
	unsigned int hash;

	hash = 0;
	points = 0;
	i = 0;
	while (i < 20)
	{
		if (str[0] != '#' && str[0] != '.')
			return (0);
		if (str[4] != '\n' && str[9] != '\n' && str[14] != '\n' && str[19] != 
				'\n')
			return (0);
		if (str[i] == '.')
<<<<<<< HEAD
			points++;
		if (str[i] == '#')
			hash++;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (hash > 4 || points > 12)
=======
			++points;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (hash > 4 || points > 12 || newlines > 5)
>>>>>>> d1f94e42c9a3f5c1cea9bca01248c1886bd32287
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_tetra(char *str)
{
	int	i;
	int x;
	int j;

	i = 0;
	x = 0;
<<<<<<< HEAD
	j = 0;
	while (i < 20)
=======
	while (i < 21)
>>>>>>> d1f94e42c9a3f5c1cea9bca01248c1886bd32287
	{
		while (str[i] && str[i] != '#')
			i++;
		while (str[i] && str[i] == '#')
		{
			i++;
			j++;
		}
		while (str[i] && str[i] != '#' && i < 20)
		{
			x++;
			i++;
		}
		if (x <= 6 && x >= 5 && j != 4)
			return (0);
		if (j == 4)
			return (1);
		if (x < 3 && str[i + 1] != '#')
			return (0);
		while (str[i] && str[i] == '#' && str[i + 1] == '#' && j < 4)
		{
			i++;
			j++;
		}
		if (j > 4)
<<<<<<< HEAD
			return (0);
		x = 0;
	}
	return (0);
=======
			return (5);
	}
	return (1);
>>>>>>> d1f94e42c9a3f5c1cea9bca01248c1886bd32287
}

int		main(int argc, char **argv)
{
	int i;
	char buf[BUF_SIZE + 1];
	int r;
	int x;

	x = 0;
	r = open(argv[1], O_RDONLY);
	if (argc == 2)
	{	
		buf[BUF_SIZE - 1] = '\0';
		while ((i = read(r, buf, BUF_SIZE)) > 0)
		{
			if (ft_checkvalidity(buf) == 1)
			{
				if ((ft_checktetra(buf)))
					x = 1;
				else
					x = 0;
			}
			else
				x = -1;
		}
//		if (i == 0)
//			x = -2;
		printf("%d", x);
	}
	return (0);
}
<<<<<<< HEAD
=======

int		ft_checkmap(char *str)
{
	char	**tab;
	int		x;
	int		y;
	int		j;
	int		a;

	x = 0;
	y = 0;
	a = 0;
	j = ft_checkline(tab[x]);
	while (y < 4)
	{
		if (j == -1 || j > 4 || a > 4)
			return (0);
		if (j > 0)
		{
			y++;
			a++;
		}

*/			

int		main(int argc, char **argv)
{
	ft_putnbr(test(argv));
	return (0);
}
>>>>>>> d1f94e42c9a3f5c1cea9bca01248c1886bd32287
