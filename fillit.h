/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:55:40 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/09 23:39:10 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRIMINOS 26
# define HASH_SIZE 40
# define BOARD_SIZE 16
# define BUF 22

typedef unsigned long long uint64_t;
typedef struct	piece{
	int			key;
	uint64_t	id;
}				Piece;
typedef struct	board {
	unsigned short		s[BOARD_SIZE];
	int					p[BOARD_SIZE * BOARD_SIZE];
}				Board;
Piece *map[HASH_SIZE];
void	ft_hash_insert(int key, uint64_t id);
Piece	*ft_hash_search(int key);
Board	*make_board(void);
#endif
