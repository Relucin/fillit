/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:42:12 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/10 00:00:38 by sbogar           ###   ########.fr       */
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


/*
void            make_hash(void)
{
    ft_hash_insert(33825, 281479271743489ULL);  //I_TALL0
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
}*/

#define SIZE 26

/*
 * note:tmp_board is a string of length cur_width * cur_width, not the size of the full board
 */

void		ft_mark_impossible(unsigned long long piece, Board tmp_board)
{
	int		i;

	i = 0;
	while (tmp_board[i])
	{
		//bit math where the piece is removed from consideration as possible from the board
		i++;
	}
}

Board		ft_populate(int cur_width, unsigned long long *pieces, Board tmp_board)
{
	int		pos;
	int		i;
	int		is_possible;

	is_possible = 0;
	i = 0;
	pos = 0;
	while (pos < cur_width * cur_width)
	{
		i = 0;
		while (pieces[i] && tmp_board[pos] != '#')
		{
			if(place_piece(tmp_board, pieces[i], pos))
			{
				tmp_board[pos] = /*bit math wherein the piece that has been considered is marked as possible*/
					//call a function that marks that piece as impossible for all other positions
				break ;	
			}
			i++;
		}
		pos++;
	}
	pos = 0;
	while (pos < cur_width * cur_width)
	{
		if (tmp_board[pos] > 1) // if there are any squares with more than one possibility marked, then there has been an unassigned piece, and we were not able to fit every piece onto a map of the given size;
			break ;
		pos++;
	}
	if (pos != cur_width * cur_width)
		return (0);
	else
		return (tmp_board);
}

char		*ft_solve(unsigned long long *pieces)
{
	char	*res;
	char	*tmp;
	int		cur_width;
	int		best_size;

	cur_width = ft_sqrrt(4 * SIZE);
	best_size = 0;
	while(cur_width != 17)
	{
		tmp = ft_populate(cur_width, pieces, /*a subsection of the board of size cur_width * cur_width */);
		if (tmp)
			if (ft_volume(tmp) < best_size)
			{
				best_size = ft_volume(tmp);
				res = tmp;
				if (best_size == 4 * SIZE)
					return (res);
			}
		cur_width++;
	}
	return (res);
}
