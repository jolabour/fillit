/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 01:57:16 by jolabour          #+#    #+#             */
/*   Updated: 2017/12/16 04:38:11 by jolabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# define BUF_SIZE 21
# define TAB0 (*map)[pos + (ft_check_x0(tab_int, l - 4, i))]
# define TAB1 (*map)[pos + (ft_check_x1(tab_int, l - 4, i))]
# define TAB2 (*map)[pos + (ft_check_x2(tab_int, l - 4, i))]

int		count_size(char *map);
void	create_map(char **map);
int		ft_check_validity(char *str, int n);
int		ft_check_tetra(char *str, const int tab[19][3]);
int		ft_stock_tetra(char *str, const int tab[19][3]);
int		ft_count_tetra(char **argv, char *buf);
int		ft_check(char **argv, int tab_int[27][3]);
int		*ft_stock_tab(char *buf, int tab_int[27][3], int j);
void	ft_map(char **map);
int		ft_check_x1(int tab[27][3], int x, int i);
int		ft_check_x0(int tab[27][3], int x, int i);
int		ft_check_x2(int tab[27][3], int x, int i);
int		ft_put_tetra(int pos, char **map, int tab_int[27][3], int i);
#endif
