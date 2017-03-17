/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:49:14 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/13 17:13:20 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void		set_board_dim(t_board *board, int dim)
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

void		resize_board(t_board *board)
{
	int		rows;

	rows = 0;
	(*board).dim += 1;
	while (rows < board->dim - 1)
		board->s[rows++] ^= 1 << (board->dim - 1);
	board->s[rows] &= ~0 ^ ((1 << board->dim) - 1);
	(*board).lpos = (board->dim - 1) + (BOARD_SIZE * (board->dim - 1));
}

t_board		*make_board(int npieces)
{
	t_board	*board;
	int		initsize;
	int		area;

	area = npieces * 4;
	initsize = 2;
	while (initsize * initsize < area)
		++initsize;
	if (!(board = malloc(sizeof(t_board))))
		return (0);
	ft_bzero(board->s, sizeof(board->s));
	set_board_dim(board, initsize);
	(*board).dim = initsize;
	(*board).lpos = (initsize - 1) + (BOARD_SIZE * (initsize - 1));
	board->npieces = npieces;
	return (board);
}
