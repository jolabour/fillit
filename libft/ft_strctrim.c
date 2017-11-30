/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 05:22:30 by jolabour          #+#    #+#             */
/*   Updated: 2017/11/21 05:27:24 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_begin(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static size_t	ft_end(char const *s, char c)
{
	size_t		i;

	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == c))
		i--;
	return (ft_strlen(s) - i - 1);
}

char			*ft_strctrim(char const *s, char c)
{
	if (!s)
		return (NULL);
	if (ft_begin(s, c) == ft_strlen(s))
		return (ft_strdup(""));
	return (ft_strsub(s, ft_begin(s, c), ft_strlen(s) - ft_end(s, c) -
				ft_begin(s, c)));
}
