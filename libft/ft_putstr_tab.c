/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:37:01 by jolabour          #+#    #+#             */
/*   Updated: 2017/11/21 01:48:31 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_tab(char **tab)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (tab[j])
		j++;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (j - 1 > i)
			ft_putchar('\n');
		i++;
	}
}
