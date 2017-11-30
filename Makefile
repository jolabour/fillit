# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 22:42:58 by ymarcill          #+#    #+#              #
#    Updated: 2017/11/26 23:25:23 by ymarcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = *.c
#./main.c ./fillit.c 

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

%.o: %.c
	gcc $(FLAGS) $(INCL) -c -o $@ $^ $(NAME)

all: $(NAME)

$(NAME): $(OBJ) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

