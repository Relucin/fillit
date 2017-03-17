/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:31:20 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/16 20:28:32 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	remove_piece(t_board *board, t_piece_c piece, int pos)
{
	t_uint64 *p;
	t_uint64 p_num;

	p_num = piece.piece->id << (pos % BOARD_SIZE);
	p = (t_uint64*)(board->s + (pos / BOARD_SIZE));
	*p = *p ^ p_num;
	if (piece.piece->fp == pos)
		piece.piece->fp = -1;
	piece.piece->lp = piece.piece->fp;
}

t_bool	place_piece(t_board *board, t_piece_c *piece, int pos)
{
	t_uint64 *p;
	t_uint64 p_num;

	p_num = piece->piece->id << (pos % BOARD_SIZE);
	p = (t_uint64*)(board->s + (pos / BOARD_SIZE));
	if (~(*p ^ p_num) & (*p | p_num))
		return (0);
	piece->bpos = pos;
	if (piece->piece->fp == -1)
		piece->piece->fp = pos;
	piece->piece->lp = pos;
	*p = *p | p_num;
	return (1);
}

void	ft_pop_res(t_board board, t_board *tmp, char *res, t_piece_c **pieces)
{
	int	i;
	int	pounds;
	int	pos;

	i = 0;
	while (pieces[i])
	{
		pounds = 0;
		pos = 0;
		place_piece(tmp, pieces[i], pieces[i]->bpos);
		while (pounds != 4)
			if (!((tmp->s[pos / board.dim] >> (pos % board.dim)) % 2))
			{
				pos++;
			}
			else
			{
				pounds++;
				res[pos] = pieces[i]->let;
				pos++;
			}
		remove_piece(tmp, *pieces[i], pieces[i]->bpos);
		i++;
	}
}

void	print_board(t_board board, t_piece_c **pieces)
{
	int		i;
	char	*res;
	t_board	*tmp;

	i = 0;
	tmp = (t_board*)malloc(sizeof(board));
	set_board_dim(tmp, board.dim);
	ft_bzero(tmp->s, board.dim * board.dim);
	res = (char*)malloc(sizeof(char) * (board.dim) * (board.dim));
	ft_memset(res, '.', (board.dim) * (board.dim));
	res[(board.dim) * (board.dim)] = 0;
	ft_pop_res(board, tmp, res, pieces);
	while (res[i])
	{
		ft_putchar(res[i]);
		i++;
		if (i % board.dim == 0)
			ft_putchar('\n');
	}
}
