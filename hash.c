/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:44:17 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/16 19:42:29 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

/*
** I_TALL0
** I_FLAT1
** T_DOWN2
** T_UP3
** T_LEFT4
** T_RIGHT5
** J_LEFT6
** J_UP7
** J_RIGHT8
** J_DOWN9
** L_RIGHT10
** L_DOWN11
** L_LEFT12
** L_UP13
** O14
** S_FLAT15
** S_TALL16
** Z_FLAT17
** Z_TALL18
*/

void	make_hash(void)
{
	ft_bzero(g_map, sizeof(g_map));
	ft_hash_insert(33825, 281479271743489ULL);
	ft_hash_insert(15, 15);
	ft_hash_insert(71, 131079);
	ft_hash_insert(113, 229377);
	ft_hash_insert(1073, 4295065601ULL);
	ft_hash_insert(1121, 4295163905ULL);
	ft_hash_insert(1569, 6442516481ULL);
	ft_hash_insert(225, 458753);
	ft_hash_insert(1059, 4295032835ULL);
	ft_hash_insert(135, 262151);
	ft_hash_insert(3105, 12884967425ULL);
	ft_hash_insert(39, 65543);
	ft_hash_insert(2115, 8590065667ULL);
	ft_hash_insert(57, 114689);
	ft_hash_insert(99, 196611);
	ft_hash_insert(51, 98307);
	ft_hash_insert(2145, 8590131201);
	ft_hash_insert(195, 393219);
	ft_hash_insert(561, 2147581953ULL);
}

int		get_hash_key(int key)
{
	return (key % HASH_SIZE);
}

void	ft_hash_insert(int key, t_uint64 id)
{
	t_piece	*piece;
	int		index;

	piece = malloc(sizeof(t_piece));
	piece->key = key;
	piece->id = id;
	piece->lp = 0;
	piece->fp = -1;
	index = get_hash_key(key);
	while (g_map[index])
	{
		++index;
		index %= HASH_SIZE;
	}
	g_map[index] = piece;
}

t_piece	*ft_hash_search(int key)
{
	int	index;

	index = get_hash_key(key);
	while (g_map[index])
	{
		if (g_map[index]->key == key)
			return (g_map[index]);
		++index;
		index %= HASH_SIZE;
	}
	return (0);
}
