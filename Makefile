# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 22:42:58 by ymarcill          #+#    #+#              #
#    Updated: 2017/12/16 04:56:49 by jolabour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c check_file.c parse.c solve.c map.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

LDFLAGS = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft $@

fclean: clean
	make -C libft $@
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
