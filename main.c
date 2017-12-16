/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:51:03 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/16 04:53:49 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	char	*map;
	int		pos;
	int		i;
	int		tab_int[27][3];

	pos = 0;
	i = 0;
	map = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	if (!ft_check(argv, tab_int) || tab_int[26][0] != 0 || tab_int[0][0] == 0)
	{
		ft_putendl("error");
		return (0);
	}
	create_map(&map);
	ft_put_tetra(pos, &map, tab_int, i);
	ft_putstr(map);
	return (0);
}
