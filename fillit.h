/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 01:57:16 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/10 02:06:20 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# define BUF_SIZE 21

//typedef struct	s_list1
//{
//	char	**tab;
//	int		x;
//	int		y;
//	t_list	*next;
//}				t_list1;

int					test(char **argv);
int					ft_check_validity(char *str, int n);
int					ft_check_tetra(char *str, const int tab[19][3]);
int					ft_stock_tetra(char *str, const int tab[19][3]);
int					ft_count_tetra(int fd, char *buf);
int					**ft_check(int argc, char **argv);

#endif
