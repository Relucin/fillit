/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:46:30 by bmontoya          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/03/10 00:02:01 by bmontoya         ###   ########.fr       */
=======
/*   Updated: 2017/03/09 23:59:54 by sbogar           ###   ########.fr       */
>>>>>>> e117b1db6124f892fb0750e53c25a2805d8311cf
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

void	place_piece(Board *board, Piece piece, int pos)
{
	unsigned long long *place;

	place = (unsigned long long*)(board->s + (pos / BOARD_SIZE));
	*place = *place ^ (piece.id << (pos % BOARD_SIZE));
}

void	print_board(Board board)
{
	int		i = 0;
	char	byte[BOARD_SIZE + 1];
	int 	subi;
	byte[BOARD_SIZE] = '\0';
	while (i < BOARD_SIZE)
	{
		if (i)
			ft_putchar('\n');
		subi = 0;
		while (subi < BOARD_SIZE)
		{
			byte[subi++] = (board.s[i] % 2) ? '#' : '.';
			board.s[i] >>= 1;
		}
		ft_putstr(byte);
		i++;
	}
	ft_putchar('\n');
}

Piece	*tetrimino_check(char *tet, int rd)
{
	int start = 0;
	int count = 0;
	int num = 1;
	while(*tet)
	{
		if (*tet == '#')
			start += (1 << count);
		else if ((*tet == '\n' && num % 5 && num != rd) || (*tet != '\n' &&*tet != '.'))
			return (0);
		if (start > 0)
			++count;
		tet++;
		num++;
	}
	return (ft_hash_search(start));
}

int		main(int argc, char **argv)
{
	char	tet[BUF];
	Piece 	*pieces[27];
	int		pn = 0;
	int		file;
	int		rd;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		make_board();
		while ((rd = read(file, tet, BUF - 1)) >= BUF -2)
		{
			tet[rd] = '\0';
			if(!(pieces[pn++] = tetrimino_check(tet, rd)))
				return (0);
		}
		pieces[pn] = 0;
		ft_putnbr(pn);
		ft_putchar('\n');
	}
}
