/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:46:30 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/10 00:55:43 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

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
		make_hash();
		file = open(argv[1], O_RDONLY);
		while ((rd = read(file, tet, BUF - 1)) >= BUF -2)
		{
			tet[rd] = '\0';
			if(!(pieces[pn++] = tetrimino_check(tet, rd)))
				return (0);
		}
		pieces[pn] = 0;
		solver(pieces, pn);
	}
}
