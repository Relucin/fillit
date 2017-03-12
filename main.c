/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:46:30 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/12 16:30:18 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

/*
**                       _oo0oo_
**                      o8888888o
**                      88" . "88
**                      (| -_- |)
**                      0\  =  /0
**                    ___/`---'\___
**                  .' \\|     |// '.
**                 / \\|||  :  |||// \
**                / _||||| -:- |||||- \
**               |   | \\\  -  /// |   |
**               | \_|  ''\---/''  |_/ |
**               \  .-\__  '-'  ___/-. /
**             ___'. .'  /--.--\  `. .'___
**          ."" '<  `.___\_<|>_/___.' >' "".
**         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
**         \  \ `_.   \_ __\ /__ _/   .-` /  /
**     =====`-.____`.___ \_____/___.-`___.-'=====
**                       `=---='
**
**
**     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**
**               佛祖保佑         永无BUG
*/

Piece_c	*make_unique_piece_c(Piece *piece, int pn)
{
	Piece_c *c_piece;

	if (!piece)
		return (0);
	if (!(c_piece = malloc(sizeof(Piece_c))))
		return (0);
	c_piece->id = piece->id;
	c_piece->bpos = 0;
	c_piece->let = 'A' + pn;
	return (c_piece);
}

Piece_c	*tetrimino_check(char *tet, int rd, int pn)
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

int		main(int argc, char **argv)
{
	char	tet[BUF];
	Piece_c	**pieces;
	int		pn;
	int		file;
	int		rd;

	pieces = (Piece_c**)malloc(sizeof(*pieces) * 27);
	pn = 0;
	if (argc == 2)
	{
		make_hash();
		file = open(argv[1], O_RDONLY);//TODO Throw an error
		while ((rd = read(file, tet, BUF - 1)) == BUF - 1)
		{
			if (!(pieces[pn] = tetrimino_check(tet, rd, pn)))
				return (0);
			++pn;
		}
		if (rd == BUF - 2)
		{
			if (!(pieces[pn] = tetrimino_check(tet, rd, pn)))//TODO Check that pn <= 26
				return (0);
			pieces[++pn] = 0;
			solver(pieces, pn);
		}
	}
}
