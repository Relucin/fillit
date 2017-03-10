/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:42:12 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/09 22:41:01 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//place a piece in the upper left
//proceed to next-highest priority square, place a piece
//		-Idea one:
//			define priority by "ghost" squares, such as the 'x' squares in the following map:
//
//			.##.															.##.
//			.#x.	highest priority would be upper-leftmost "ghost" --> 	.#0.
//			.#x.															.#..
//			....															....
//
//			x#x.															0#..
//			###.															###.
//			....															....
//			....															....
//		
//		-Idea two:
//			define priority  as minimizing volume
//				*would need a volume defining function for every new consideration
//					 -> I'm not a huge fan of this method


//Idea one expansion:
//
//		-would require an id in the piece struct similar to the original id, but which would define the ghost square
//			->again, touch base with brandon
//
//		-check squares surrounding ghost for possible shapes that would fill the ghost, then place those
//			->each co-ordinate on the board needs to have a "filled" or "not filled" condition, in addition to the
	//				"possible" and "not possible" conditions, which refer to starting co-ordinates for pieces
//				*three dimensional array? An additional array of size [256]?
//
//		-if, in our progression, we discover a ghost square that cannot be filled, recurse
//			->how likely is it that the optimal shape would have unfilled ghost squares?
//				*not very, I would wager
//			->most pieces on edge of final shape will have ghosts. How will we know when to stop trying to fill them?
//				*I really want to avoid calling a volume-checking function on every new placement
//
//		!!!	what is our recurse condition?	!!!
//

char		*ft_populate(int cur_width, struct piece *map)
{
	
}

char		*ft_solve(struct piece *map)
{
	char	*res;
	char	*tmp;
	int		cur_width;
	int		best_size;

	cur_width = ft_sqrrt(4 * SIZE);
	best_size = 0;
	while(1)
	{
		tmp = ft_populate(cur_width, map);
		if (ft_volume(tmp) < best_size)
		{
			best_size = ft_volume(tmp);
			res = tmp;
			if (best_size == 4 * SIZE)
				return (res);
		}
		cur_width++;
	}
	return (NULL);
}
