/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:44:33 by jolabour          #+#    #+#             */
/*   Updated: 2017/11/26 08:09:34 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

char	*ft_buf(char **argv)
{
	int ret;
	int fd;
	char buf[BUF_SIZE + 1];
	char *str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!(str = (char *)malloc(sizeof(char) * ret)))
		return (NULL);
	ft_strcpy(str, buf);
	if (close(fd) == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	return (str);
}
