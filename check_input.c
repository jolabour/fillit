#include "fillit.h"

size_t		check_input(int argc, char **argv)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
	{
		while (argv[1][i])
		{
			if (argv[1][i] != '#' && argv[1][i] != '.' && argv[1][i] != '\n')
			{
				ft_putstr("error\n");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	check_input(argc, argv);
	return (0);
}
