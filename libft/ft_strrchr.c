/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:07:15 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/03 14:39:47 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	l;
	char			cc;

	i = 0;
	l = 0;
	cc = (char)c;
	while (s[i])
		if (s[i++] == cc)
			l = i - 1;
	if (s[i] == cc)
		return ((char*)(s + i));
	else if (s[l] == cc)
		return ((char*)(s + l));
	return (NULL);
}
