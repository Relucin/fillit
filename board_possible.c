/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:31:43 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/09 19:19:53 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 26

struct piece board[256][SIZE];

//file should return a board with every square being marked as being possible for the starting co-ordinate for a piece

void	ft_mark_impossible(struct piece *map)
{
	//defining possibilities is tricky. Review implications of id's with Brandon
}

void	ft_populate_possible(struct piece board[256][SIZE])
{
	int	i;

	i = 0;
	while (i < 256)
	{
		board[i] = ft_mark_impossible(map);
		i++;
	}
}
