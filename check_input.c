/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:58:07 by jolabour          #+#    #+#             */
/*   Updated: 2017/11/26 09:10:25 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_convert_to_tab(char *str)
{
	char	***tab;
	int		i;
	int		j;
	int		x;
	int		y;
	int		len;


	j = 0;
	i = 0;
	x = 0;
	y = 0;
	len = ft_strlen(str) / 21;
	if (!(tab = (char ***)malloc(sizeof(char **) * ((ft_strlen(str) / 21) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		y = 0;
		while (y < 4)
		{
			tab[j] = (char **)malloc(sizeof(char *) * 5);
			x = 0;
			while (x < 5)
			{
				tab[j][y] = (char *)malloc(sizeof(char) * 6);
				tab[j][y][x] = str[i];
				//ft_putchar(tab[j][y][x]);
				x++;
				i++;
			}
			tab[j][y][x] = '\0';
			//ft_putstr(**tab);
			y++;
		}
		ft_putnbr(y);
		tab[j][y] = 0;
		j++;
		if (len > 1)
			i++;
	}
	tab[j] = 0;
	return (tab);
}

void	print_tab(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_tab(tab[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	ft_convert_to_tab(ft_buf(argv));
	return (0);
}


