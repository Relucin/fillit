/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:44:17 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/09 22:39:53 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

typedef piece{
//	long long		key;
	unsigned long long	place;
//	long long		id;
	unsigned int	height;
}		Piece;


Piece *map[SIZE];

long long			get_hash_key(unsigned long long place)
{
	return (place % SIZE);
}

void				ft_hash_insert(unsigned long long place, unsigned int height)
{
	struct piece	*res;
	long long		index;

	res = (struct piece*)malloc(sizeof(Piece));
	res->height = height;
	res->place = place;

	index = get_hash_key(place);
	while (map[index] && map[index]->place != -1)
	{
		++index;
		index %= SIZE;
	}
	map[index] = res;
}

struct piece	*ft_hash_search(unsigned long long place)
{
	int	index;

	index = get_hash_key(place);

	while(map[index])
	{
		if(map[index] != NULL)
			return (map[index]);
		++index;
		index %= SIZE;
	}
	return (NULL);
}
