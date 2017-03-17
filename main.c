/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:46:30 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/16 16:29:55 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

t_bool			error(int flag)
{
	if (!flag)
		ft_putendl("error");
	else if (flag == 2)
		ft_putendl("usage: fillit source_file");
	return (flag);
}

t_piece_c		*make_unique_piece_c(t_piece *piece, int pn)
{
	t_piece_c *c_piece;

	if (!piece)
		return (0);
	if (!(c_piece = malloc(sizeof(t_piece_c))))
		return (0);
	c_piece->piece = piece;
	c_piece->bpos = 0;
	c_piece->let = 'A' + pn;
	return (c_piece);
}

t_piece_c		*tetrimino_check(char *tet, int rd, int pn)
{
	int val;
	int shift;
	int loc;

	val = 0;
	shift = 0;
	loc = 0;
	tet[rd] = '\0';
	while (tet[loc])
	{
		if (tet[loc] == '#')
			val += 1 << shift;
		else if (tet[loc] == '\n')
		{
			if ((loc + 1) % 5 && !(rd == BUF - 1 && loc == BUF - 2))
				return (0);
		}
		else if (tet[loc] != '.')
			return (0);
		if (val)
			++shift;
		++loc;
	}
	return (make_unique_piece_c(ft_hash_search(val), pn));
}

t_bool			read_file(t_piece_c **pieces, int file)
{
	int		rd;
	char	tet[BUF];
	int		pn;

	make_hash();
	pn = 0;
	while ((rd = read(file, tet, BUF - 1)) == BUF - 1)
	{
		if (pn >= 26 || !(pieces[pn] = tetrimino_check(tet, rd, pn)))
			return (0);
		++pn;
	}
	if (rd == BUF - 2)
	{
		if (pn >= 26 || !(pieces[pn] = tetrimino_check(tet, rd, pn)))
			return (0);
		pieces[++pn] = 0;
		solver(pieces, pn);
	}
	else
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_piece_c	**pieces;
	int			file;

	pieces = (t_piece_c**)malloc(sizeof(*pieces) * 27);
	if (argc == 2)
	{
		if (!(file = open(argv[1], O_RDONLY)))
			return (error(0));
		return (error(read_file(pieces, file)));
	}
	return (error(2));
}
