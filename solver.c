/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 00:26:57 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/12 16:38:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
t_bool	rec_solver(Board *board, Piece_c **pieces)
{
	int pos;
	
	if (!*pieces)
		return (1);
	pos = 0;
	while (pos < board->lpos)
	{
		while (!place_piece(board,**pieces, pos))
		{
			if(++pos > board->lpos)
				return (0);
		}
		/*if (board->solved)
		{
			if (compare_board(board))
				rec_solver(board, &(pieces[1]));
			else
			{
				remove_piece(board, **pieces, pos);
				return (1);
			}
		}
		else*/
		if (rec_solver(board, &(pieces[1])))
			return (1);
		remove_piece(board, **pieces, pos);
		pos++;
	}
	return (0);
}
void	solver(Piece_c **pieces, int npieces)
{
	Board *board;
	board = make_board(npieces);
	while(!rec_solver(board, pieces))
		resize_board(board);
	print_board(*board);
}
