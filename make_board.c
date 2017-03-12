/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:49:14 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/12 00:43:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	set_board_dim(Board *board, int dim)
{
	int	shift;
	int row;

	row = 0;
	shift = ~0 ^ ((1 << dim) - 1);
	while (row < dim)
		board->s[row++] |= shift;
	while (row < BOARD_SIZE)
		ft_memset(board->s + row++, 255,sizeof(board->s));
}

void	remove_piece(Board *board, Piece piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;

	p_num = piece.id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	*p = *p ^ p_num;
}

t_bool	place_piece(Board *board, Piece piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;

	p_num = piece.id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	if (~(*p ^ p_num) & (*p | p_num))
		return (0);
	*p = *p | p_num;
	return (1);
}

void	resize_board(Board *board)
{
	int rows;

	rows = 0;
	(*board).dim += 1;
	while (rows < board->dim - 1)
		board->s[rows++] ^= 1 << (board->dim - 1);
	board->s[rows] &=  ~0 ^ ((1 << board->dim) - 1);
	(*board).lpos = (board->dim - 1) + (BOARD_SIZE * (board->dim - 1));
}
void	print_board(Board board)
{
	int		i = 0;
	char	byte[BOARD_SIZE + 1];
	int 	subi;
	byte[board.dim] = '\0';
	while (i < board.dim)
	{
		if (i)
			ft_putchar('\n');
		subi = 0;
		while (subi < board.dim)
		{
			byte[subi++] = (board.ss[i] % 2) ? '#' : '.';
			board.ss[i] >>= 1;
		}
		ft_putstr(byte);
		i++;
	}
	ft_putchar('\n');
}

t_bool	compare_board(Board *board)
{
	int pos;

	pos = board->dim - 1;
	while (pos && board->s[pos] == board->ss[pos])
		--pos;
	if (board->s[pos] < board->ss[pos])
		return (1);
	return (0);
}

Board	*make_board(int npieces)
{
	Board	*board;
	int 	initsize;
	int		area;

	area = npieces * 4;
	initsize = 2;
	while (initsize * initsize < area)
		++initsize;
	if (!(board = malloc(sizeof(Board))))
		return (0);
	ft_bzero(board->s, sizeof(board->s));
	ft_memset(board->ss, 255, sizeof(board->s));
	set_board_dim(board, initsize);
	(*board).dim = initsize;
	(*board).lpos = (initsize - 1) + (BOARD_SIZE * (initsize - 1));
	(*board).solved = 0;
	return (board);
}
