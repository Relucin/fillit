# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbogar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/12 19:06:04 by sbogar            #+#    #+#              #
#    Updated: 2017/03/12 21:26:32 by bmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LINKER = -Llibft/ -lft

FLAGS = -Wall -Werror -Wextra

SRCS = make_board.c pieces.c hash.c solver.c

BIN = $(SRCS:.c=.o)

all: $(NAME)

libft.a:
	@make -C libft/

$(NAME): libft.a $(BIN)
	@gcc $(BIN) $(FLAGS) $(LINKER) main.c -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@rm -f $(BIN)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
