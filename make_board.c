/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:49:14 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/10 19:15:03 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

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

void	make_hash(void)
{
	ft_bzero(map,sizeof(map));
	ft_hash_insert(33825, 281479271743489ULL);	//I_TALL0
	ft_hash_insert(15, 15); //I_FLAT1
	ft_hash_insert(71, 131079); //T_DOWN2
	ft_hash_insert(113, 229377); //T_UP3
	ft_hash_insert(1073, 4295065601ULL); //T_LEFT4
	ft_hash_insert(1121, 4295163905ULL); //T_RIGHT5
	ft_hash_insert(1569, 6442516481ULL); //J_LEFT6
	ft_hash_insert(225, 458753); //J_UP7
	ft_hash_insert(1059, 4295032835ULL); //J_RIGHT8
	ft_hash_insert(135,262151); //J_DOWN9
	ft_hash_insert(3105,12884967425ULL); //L_RIGHT10
	ft_hash_insert(39,65543); //L_DOWN11
	ft_hash_insert(2115,8590065667ULL); //L_LEFT12
	ft_hash_insert(57,114689); //L_UP13
	ft_hash_insert(99,196611); //O14
	ft_hash_insert(51,98307); //S_FLAT15
	ft_hash_insert(2145,8590131201); //S_TALL16
	ft_hash_insert(195,393219); //Z_FLAT17
	ft_hash_insert(561,2147581953ULL); //Z_TALL18
}

Board	*make_board(int npieces)
{
	Board *board;
	if (!(board = malloc(sizeof(board))))
		return (0);
	ft_bzero(board->s, sizeof(board->s));
	ft_bzero(board->p, sizeof(board->p));
	return (board);
}
