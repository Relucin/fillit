/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 00:26:57 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/12 00:59:10 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
t_bool	rec_solver(Board *board, Piece **pieces)
{
	int pos;
	
	if (!*pieces)
	{
		if(compare_board(board))
			ft_memcpy(board->ss, board->s, sizeof(board->s));
		board->solved = 1;
		return (1);
	}
	pos = 0;
	while (pos < board->lpos)
	{
		while (!place_piece(board,**pieces, pos))
		{
			if(++pos > board->lpos)
				return (board->solved);
		}
		if (board->solved)
		{
			if (compare_board(board))
				rec_solver(board, &(pieces[1]));
			else
			{
				remove_piece(board, **pieces, pos);
				return (1);
			}
		}
		else	
			rec_solver(board, &(pieces[1]));
		remove_piece(board, **pieces, pos);
		pos++;
	}
	return (0);
}
void	solver(Piece **pieces, int npieces)
{
	Board *board;
	board = make_board(npieces);
	while (!board->solved)
	{
		if(!rec_solver(board, pieces))
			resize_board(board);
	}
	print_board(*board);
}
