/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:48:43 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/07 18:32:48 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

e_block		verify_block(int b)
{
	if (b > 500)
		return (b == I_FLAT || b == L_TOP || b == J_TOP ||
		b == S_TALL || b == T_RIGHT || b == J_RIGHT) ? b : ERROR;
	else if (b > 400)
		return (b == T_LEFT || b == Z_TALL || b == T_TOP) ? b : ERROR;
	else if (b == L_LEFT)
		return (b);
	else if (b > 100)
		return (b == L_BOTTOM || b == Z_FLAT || b == J_BOTTOM ||
		b == O || b == S_FLAT || b == J_LEFT ||
		b == T_BOTTOM || b == L_RIGHT || b == I_TALL) ? b : ERROR;
	else
		return (ERROR);
}

e_block		tetrimino_check(char *tet, int rd)
{
	int				d[4];
	unsigned int	i;
	unsigned int	c;
	unsigned int	t;

	i = 0;
	c = 0;
	t = 0;
	while (tet[c] == '.' || tet[c] == '\n' || tet[c] == '#')
	{
		if (tet[c] == '#')
		{
			if (i == 4 || ((c == 2 || c > 5) && i > 0))
				return (ERROR);
			d[i++] = c;
			tet += c;
			c = 0;
		}
		if (tet[c] == '\n' && t % 4)
			return (ERROR);
		t += (tet[c] != '\n') ? 1 : 0;
		c++;
	}
	return (i == 4 && (int)t == rd - 4 - (rd % 20))
	? verify_block((d[1] * 100) + (d[2] * 10) + d[3]) : 0;
}
