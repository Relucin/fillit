/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:34:54 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/08 00:09:54 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"
#include <stdio.h>
#define MAX_AREA 6163

void	set_board(char *board)
{
	int loc;

	loc = 0;
	while (loc < MAX_AREA - 1)
	{
		board[loc] = ((loc + 1) % (79)) ? '.' : '\n';
		++loc;
	}
	board[loc] = '\0';
}

int		get_new_loc(int i)
{
	if (i == 1)
		return (1);
	else if (i == 4)
		return (76);
	else if (i == 3)
		return (77);
	else
		return (79);
}

void	place_piece(char *board, e_block piece, int loc)
{
	int part;

	printf("%d\n", piece);
	board[loc] = '#';
	part = get_new_loc(piece / 100);
	board[loc + part] = '#';
	loc += part;
	part = get_new_loc((piece % 100) / 10);
	board[loc + part] = '#';
	loc += part;
	part = get_new_loc(piece % 10);
	board[loc + part] = '#';
}

void	solver(e_block *tets, int nbr)
{
	char board[MAX_AREA];
	(void)tets;
	(void)nbr;
	set_board(board);
	place_piece(board,tets[1], (3*29));
	printf("%s", board);	
}
