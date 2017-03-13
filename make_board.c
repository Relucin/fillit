/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:49:14 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/12 19:01:35 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void		set_board_dim(Board *board, int dim)
{
	int		shift;
	int		row;

	row = 0;
	shift = ~0 ^ ((1 << dim) - 1);
	while (row < dim)
		board->s[row++] |= shift;
	while (row < BOARD_SIZE)
		ft_memset(board->s + row++, 255, sizeof(board->s));
}

void		resize_board(Board *board)
{
	int		rows;

	rows = 0;
	(*board).dim += 1;
	while (rows < board->dim - 1)
		board->s[rows++] ^= 1 << (board->dim - 1);
	board->s[rows] &= ~0 ^ ((1 << board->dim) - 1);
	(*board).lpos = (board->dim - 1) + (BOARD_SIZE * (board->dim - 1));
}

Board		*make_board(int npieces)
{
	Board	*board;
	int		initsize;
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
	board->npieces = npieces;
	return (board);
}
