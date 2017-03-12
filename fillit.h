/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:55:40 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/12 16:33:02 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRIMINOS 26
# define HASH_SIZE 40
# define BOARD_SIZE 16
# define BUF 22

typedef unsigned long long	uint64_t;
typedef unsigned char		t_bool;
typedef struct	piece_c{
	char		let;
	uint64_t	id;
	int			bpos;
}				Piece_c;
typedef struct	piece{
	int			key;
	uint64_t	id;
}				Piece;
typedef struct	board {
	unsigned short		s[BOARD_SIZE];
	int					dim;
	int					lpos;
	int					solved;
	unsigned short		ss[BOARD_SIZE];
}				Board;
Piece *map[HASH_SIZE];
void	ft_hash_insert(int key, uint64_t id);
Piece	*ft_hash_search(int key);
Board	*make_board(int npieces);
void	solver(Piece_c **pieces, int npieces);
void	print_board(Board board);
t_bool	place_piece(Board *board, Piece_c piece, int pos);
void	resize_board(Board *board);
void	remove_piece(Board *board, Piece_c piece, int pos);
t_bool	compare_board(Board *board);
void	make_hash(void);
#endif
