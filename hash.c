/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:44:17 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/11 17:04:50 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

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

int		get_hash_key(int key)
{
	return (key % MAX_TETRIMINOS);//TODO Change to hash_size???
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
