#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>

# define BUF_SIZE 4096
size_t		ft_tab_test(char **argv);
char		*ft_buf(char **argv);
void		print_tab(char ***tab);
char		***ft_convert_to_tab(char *str);
#endif
