/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:43:14 by bmontoya          #+#    #+#             */
/*   Updated: 2017/02/28 20:04:40 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		loc;

	loc = 0;
	if (!(dup = (char*)malloc(sizeof(*dup) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (*s1)
		dup[loc++] = *s1++;
	dup[loc] = '\0';
	return (dup);
}
