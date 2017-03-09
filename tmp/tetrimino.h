/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:04:13 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/07 18:37:16 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

typedef enum	tetrimino
{
	ERROR = 0,
	I_TALL = 111,
	L_RIGHT = 113,
	T_BOTTOM = 114,
	J_LEFT = 115,
	S_FLAT = 131,
	O = 141,
	J_BOTTOM = 145,
	Z_FLAT = 151,
	L_BOTTOM = 155,
	L_LEFT = 311,
	T_TOP = 411,
	Z_TALL = 414,
	T_LEFT = 415,
	J_RIGHT = 511,
	T_RIGHT = 514,
	S_TALL = 515,
	J_TOP = 541,
	L_TOP = 551,
	I_FLAT = 555
}				e_block;

e_block			tetrimino_check(char *tet, int rd);
void			solver(e_block *tets, int nbr);
#endif
