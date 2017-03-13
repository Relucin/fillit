/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:31:20 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/12 19:02:42 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	remove_piece(Board *board, Piece_c piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;

	p_num = piece.id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	*p = *p ^ p_num;
}

t_bool	place_piece(Board *board, Piece_c *piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;

	p_num = piece->id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	if (~(*p ^ p_num) & (*p | p_num))
		return (0);
	piece->bpos = pos;
	*p = *p | p_num;
	return (1);
}

void	ft_pop_res(Board board, Board *tmp, char *res, Piece_c **pieces)
{
	int	i;
	int	pounds;
	int	pos;

	i = 0;
	while (pieces[i])
	{
		pounds = 0;
		pos = 0;
		place_piece(tmp, pieces[i], pieces[i]->bpos);
		while (pounds != 4)
			if (!((tmp->s[pos / board.dim] >> (pos % board.dim)) % 2))
			{
				pos++;
			}
			else
			{
				pounds++;
				res[pos] = pieces[i]->let;
				pos++;
			}
		remove_piece(tmp, *pieces[i], pieces[i]->bpos);
		i++;
	}
}

void	print_board(Board board, Piece_c **pieces)
{
	int		i;
	char	*res;
	Board	*tmp;

	i = 0;
	tmp = (Board*)malloc(sizeof(board));
	set_board_dim(tmp, board.dim);
	res = (char*)malloc(sizeof(char) * (board.dim) * (board.dim));
	ft_memset(res, '.', (board.dim) * (board.dim));
	res[(board.dim) * (board.dim)] = 0;
	ft_pop_res(board, tmp, res, pieces);
	while (res[i])
	{
		ft_putchar(res[i]);
		i++;
		if (i % board.dim == 0)
			ft_putchar('\n');
	}
}
