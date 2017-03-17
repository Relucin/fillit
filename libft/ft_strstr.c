/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:39:39 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 18:45:29 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int f;
	unsigned int s;

	f = 0;
	s = 0;
	if (!big[0] && !little[0])
		return ((char*)big);
	while (big[f])
	{
		if (!little[s])
			return ((char*)(big + f));
		if (big[f + s] == little[s])
		{
			s++;
			continue;
		}
		s = 0;
		f++;
	}
	return (NULL);
}
