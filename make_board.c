/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:49:14 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/10 21:32:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	set_board_dim(Board *board, int dim)
{
	int	shift;
	int row;

	row = 0;
	shift = ~0 ^ ((1 << dim) - 1);
	while (row < dim)
		board->s[row++] |= shift;
	while (row < BOARD_SIZE)
		ft_memset(board->s + row++, 255,sizeof(board->s));
}
t_bool	place_piece(Board *board, Piece piece, int pos)
{
	uint64_t *p;
	uint64_t p_num;
	
	p_num = piece.id << (pos % BOARD_SIZE);
	p = (uint64_t*)(board->s + (pos / BOARD_SIZE));
	if (~(*p ^ p_num) & (*p | p_num))
		return (0);
	*p = *p ^ p_num;
	return (1);
}

void	resize_board(Board *board)
{
	
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


Board	*make_board(int npieces)
{
	Board *board;
	if (!(board = malloc(sizeof(board))))
		return (0);
	ft_bzero(board->s, sizeof(board->s));
	ft_bzero(board->p, sizeof(board->p));
	set_board_dim(board, 10);
	return (board);
}
