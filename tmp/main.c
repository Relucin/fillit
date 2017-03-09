/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:06:28 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/07 18:37:39 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFFER 22
#define MAX_TETRIMINOS 27
#include "tetrimino.h"
#include <string.h> //REMOVEEEEEEEEEEE
#include <stdio.h> //REMOVEEEEEEE

/*
void		place_board(int loc, int block, char *board)
{
	board += loc;
	board[0] = '#';
	board[((block % 1000) / 100) + (26 * 3) - 4] = '#';
	board += 26 * 3 + 1;
	board[((block % 100) / 10) + (26 * 3) - 4] = '#';
	board += 26 * 3 + 1;
	board[(block % 10) + (26 * 3) - 4] = '#';
}

void		build_board(char *board)
{
	int loc;

	loc = 0;
	while(loc < 6161)
	{
		board[loc] = ((loc + 1) % (3 * 26 + 1)) ? '.' : '\n';
		loc++;
	}
	board[loc] = '\0';
}*/

int		main(int argc, char **argv)
{
	char	tet[BUFFER];
	e_block	tetriminos[MAX_TETRIMINOS];
	int		i;
	int		rd;
	int		x;

	if (argc == 2)
	{
		i = open(argv[1], O_RDONLY);
		x = 0;
		while ((rd = read(i, tet, BUFFER - 1)) >= BUFFER - 2)
		{
			tet[rd] = '\0';
			if (!(tetriminos[x++] = tetrimino_check(tet, rd)))
				break ;
		}
		close(i);
		if (!rd && x < MAX_TETRIMINOS - 1)
			solver(tetriminos, x);
	}
}
