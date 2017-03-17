/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:55:40 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/16 19:39:37 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRIMINOS 26
# define HASH_SIZE 42
# define BOARD_SIZE 16
# define BUF 22

typedef unsigned long long	t_uint64;
typedef unsigned char		t_bool;
typedef struct				s_piece{
	int						key;
	t_uint64				id;
	int						fp;
	int						lp;
}							t_piece;
typedef struct				s_piece_c{
	char					let;
	t_piece					*piece;
	int						bpos;
}							t_piece_c;
typedef struct				s_board {
	unsigned short			s[BOARD_SIZE];
	int						npieces;
	int						dim;
	int						lpos;
}							t_board;
void						set_board_dim(t_board *board, int dim);
t_piece						*g_map[HASH_SIZE];
void						ft_hash_insert(int key, t_uint64 id);
t_piece						*ft_hash_search(int key);
t_board						*make_board(int npieces);
void						solver(t_piece_c **pieces, int npieces);
void						print_board(t_board board, t_piece_c **pieces);
t_bool						place_piece(t_board *b, t_piece_c *piece, int pos);
void						resize_board(t_board *board);
void						remove_piece(t_board *b, t_piece_c piece, int pos);
t_bool						compare_board(t_board *board);
void						make_hash(void);
void						set_board_dim(t_board *board, int dim);
#endif
