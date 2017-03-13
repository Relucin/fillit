# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbogar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/12 19:06:04 by sbogar            #+#    #+#              #
#    Updated: 2017/03/12 20:09:42 by sbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra  -Llibft/ -lft

SRCS = pieces.c hash.c make_board.c solver.c

BIN = $(SRCS:.c=.o)

all: $(NAME)

libft.a:
	make -C libft/

$(NAME): libft.a $(BIN)
	gcc $(SRCS) $(FLAGS) main.c -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $^

clean:
	rm -f $(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all
