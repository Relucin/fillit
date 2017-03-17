/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 00:26:57 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/16 20:24:29 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	reset_pieces(t_piece_c **pieces)
{
	while (*pieces)
	{
		(*pieces)->piece->lp = 0;
		(*pieces)->piece->fp = -1;
		++pieces;
	}
}

t_bool	rec_solver(t_board *board, t_piece_c **pieces)
{
	int pos;

	if (!*pieces)
		return (1);
	pos = (*pieces)->piece->lp;
	while (pos < board->lpos)
	{
		while (!place_piece(board, *pieces, pos))
		{
			if (++pos > board->lpos)
				return (0);
		}
		if (rec_solver(board, &(pieces[1])))
			return (1);
		remove_piece(board, **pieces, pos);
		pos++;
	}
	return (0);
}

void	solver(t_piece_c **pieces, int npieces)
{
	t_board *board;

	board = make_board(npieces);
	while (!rec_solver(board, pieces))
	{
		reset_pieces(pieces);
		resize_board(board);
	}
	print_board(*board, pieces);
}
