/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:44:17 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/09 23:45:44 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"


int		get_hash_key(int key)
{
	return (key % MAX_TETRIMINOS);
}

void	ft_hash_insert(int key, uint64_t id)
{
	Piece	*piece;
	int		index;

	piece = malloc(sizeof(Piece));
	piece->key = key;
	piece->id = id;
	index = get_hash_key(key);
	while (map[index])// && map[index]->key != -1)
	{
		++index;
		index %= HASH_SIZE;
	}
	map[index] = piece;
}

Piece	*ft_hash_search(int key)
{
	int	index;

	index = get_hash_key(key);
	while(map[index])
	{
		if(map[index] != NULL)
			return (map[index]);
		++index;
		index %= HASH_SIZE;
	}
	return (NULL);
}
