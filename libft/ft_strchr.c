/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:36:42 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/03 14:29:46 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char cc;

	cc = (char)c;
	while (*s)
		if (*s++ == cc)
			return ((char*)--s);
	if (*s == cc)
		return ((char*)s);
	else
		return (NULL);
}
