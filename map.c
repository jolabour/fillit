/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:27:00 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/16 04:31:57 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_size(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

void	ft_map(char **map)
{
	int i;
	int n;
	int l;

	n = 1;
	i = 0;
	l = count_size(*map) + 1;
	free(*map);
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
}

void	create_map(char **map)
{
	int l;
	int i;
	int n;

	n = 1;
	i = 0;
	l = 2;
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
}
