/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:49:14 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/12 18:20:24 by sbogar           ###   ########.fr       */
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

void	remove_piece(Board *board, Piece_c piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;

	p_num = piece.id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	*p = *p ^ p_num;
}

t_bool	place_piece(Board *board, Piece_c *piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;

	p_num = piece->id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	if (~(*p ^ p_num) & (*p | p_num))
		return (0);
	piece->bpos = pos;
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

void	print_board(Board board, Piece_c **pieces)
{
	int		i;
	int		pounds;
	int		pos;
	char	*res;
	Board	*tmp;

	i = 0;
	pos = 0;
	tmp = (Board*)malloc(sizeof(board));
	set_board_dim(tmp, board.dim); 
	res = (char*)malloc(sizeof(char) * (board.dim) * (board.dim));
	ft_memset(res, '.', (board.dim) * (board.dim));
	res[(board.dim) * (board.dim)] = 0;
	while (pieces[i])
	{
		pounds = 0;
		pos = 0;
		place_piece(tmp, pieces[i], pieces[i]->bpos);
		while(pounds != 4)
		{
			if (!((tmp->s[pos / board.dim]>>(pos % board.dim)) % 2))
			{
				pos++;
			}
			else
			{
				pounds++;
				res[pos] = pieces[i]->let;
				pos++;
			}
		}
		remove_piece(tmp, *pieces[i], pieces[i]->bpos);
		i++;
	}
	i = 0;
	while (res[i])
	{
		ft_putchar(res[i]);
			i++;
		if (i % board.dim == 0)
			ft_putchar('\n');
	}
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
	board->npieces = npieces;
	return (board);
}
