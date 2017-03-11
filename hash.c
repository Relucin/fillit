/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:44:17 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/10 18:35:09 by bmontoya         ###   ########.fr       */
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
	while (map[index])
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
		if(map[index]->key == key)
			return (map[index]);
		++index;
		index %= HASH_SIZE;
	}
	return (0);
}

/*
**                       _oo0oo_
**                      o8888888o
**                      88" . "88
**                      (| -_- |)
**                      0\  =  /0
**                    ___/`---'\___
**                  .' \\|     |// '.
**                 / \\|||  :  |||// \
**                / _||||| -:- |||||- \
**               |   | \\\  -  /// |   |
**               | \_|  ''\---/''  |_/ |
**               \  .-\__  '-'  ___/-. /
**             ___'. .'  /--.--\  `. .'___
**          ."" '<  `.___\_<|>_/___.' >' "".
**         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
**         \  \ `_.   \_ __\ /__ _/   .-` /  /
**     =====`-.____`.___ \_____/___.-`___.-'=====
**                       `=---='
**
**
**     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**
**               佛祖保佑         永无BUG
*/
