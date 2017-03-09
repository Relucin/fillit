/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:46:30 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/09 15:06:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#define BOARD_SIZE 16
#define BUF 22

typedef struct	piece {
	unsigned long long	place;
	unsigned int		height;
}				Piece;

typedef union	board {
	unsigned int		i[BOARD_SIZE / 2];
	unsigned short		s[BOARD_SIZE];
	unsigned char		c[BOARD_SIZE * 2];
}				Board;
void	place_piece(Board *board, Piece piece, int pos)// int locx, int locy
{
	unsigned long long *place;

	place = (unsigned long long*)(board->s + (pos / BOARD_SIZE));//locx);
	*place = *place ^ (piece.place << (pos % BOARD_SIZE)); //locy);
}
void	print_board(Board board)
{
	int		i = 0;
	char	byte[BOARD_SIZE + 1];
	int 	subi;
	byte[BOARD_SIZE] = '\0';
	while (i < BOARD_SIZE)
	{
		if (i)
			ft_putchar('\n');
		subi = 0;
		while (subi < BOARD_SIZE)
		{
			byte[subi++] = (board.s[i] % 2) ? '#' : '.';
			board.s[i] >>= 1;	
		}
		ft_putstr(byte);
		i++;
	}
	ft_putchar('\n');
}
void	tetrimino_check(char *tet)
{
	long long nbrs[][2] = {{33825, 65537}, //I_TALL
							};
	int start = 0;
	int count = 0;
	ft_putstr(tet);
	while(*tet)
	{
		if (*tet == '#')
			start += (1 << count);
		if (start > 0)
			++count;
		tet++;
	}
	ft_putnbr(start);
	ft_putendl("");
	Board test;
	Piece ptest;
	ft_memset(test.c, 0,sizeof(test.c));
	ptest.place = 1ULL + (1ULL << BOARD_SIZE) + (1ULL << (BOARD_SIZE *2)) + (1ULL << (BOARD_SIZE * 3));
	ptest.height = 4;
	ft_putendl(ft_itoa(ptest.place));
	place_piece(&test,ptest ,0);
	print_board(test);
}

int		main(int argc, char **argv)
{
	char	tet[BUF];
	int		file;
	int		rd;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while ((rd = read(file, tet, BUF - 1)) >= BUF -2)
		{
			tet[rd] = '\0';
			tetrimino_check(tet);
		}
	}
}
