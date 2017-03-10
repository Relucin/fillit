/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:46:30 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/09 22:41:06 by sbogar           ###   ########.fr       */
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

unsigned long long nbrs[][2] = {{33825, 281479271743489ULL}, //I_TALL0
								{15, 15}, //I_FLAT1
								{71, 131079}, //T_DOWN2
								{113, 229377}, //T_UP3
								{1073, 4295065601ULL}, //T_LEFT4
								{1121, 4295163905ULL}, //T_RIGHT5
								{1569, 6442516481ULL}, //J_LEFT6
								{225, 458753}, //J_UP7
								{1059, 4295032835ULL}, //J_RIGHT8
								{135,262151}, //J_DOWN9
								{3105,12884967425ULL}, //L_RIGHT10
								{39,65543}, //L_DOWN11
								{2115,8590065667ULL}, //L_LEFT12
								{57,114689}, //L_UP13
								{99,196611}, //O14
								{51,98307}, //S_FLAT15
								{2145,8590131201}, //S_TALL16
								{195,393219}, //Z_FLAT17
								{561,2147581953ULL} //Z_TALL18
								};

unsigned long long	tetrimino_check(char *tet, int rd)
{
	int start = 0;
	int count = 0;
	int test = 0;
	int num = 1;
	while(*tet)
	{
		if (*tet == '#')
			start += (1 << count);
		else if ((*tet == '\n' && num % 5 && num != rd) || *tet != '.')
			return (0);
		if (start > 0)
			++count;
		tet++;
		num++;
	}
	while (test < 19)
	{
		if (nbrs[test][0] == start)
			return (nbrs[test][1]);
		test++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char				tet[BUF];
	unsigned long long 	pieces[27];
	int					pn = 0;
	int					file;
	int					rd;
	struct piece		**map;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while ((rd = read(file, tet, BUF - 1)) >= BUF -2)
		{
			tet[rd] = '\0';
			if(!(pieces[pn++] = tetrimino_check(tet, rd)))
				return (0);
		}
		pieces[pn] = 0;
	}
}
