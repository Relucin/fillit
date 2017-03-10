/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 00:26:57 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/10 14:23:41 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solver(Piece **pieces, int npieces)
{
	Board *board;

	board = make_board(npieces);
	place_piece(board,*pieces[0],0);
	place_piece(board,*pieces[1],5);
	print_board(*board);
}

void	generate_pos(Board *board, Piece **pieces)
{
	
}
