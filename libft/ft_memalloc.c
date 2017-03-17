/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:26:42 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 01:14:00 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;
	char *tmp;

	if (!size || !(mem = malloc(size)))
		return (NULL);
	tmp = (char*)mem;
	while (--size)
		*tmp++ = 0;
	*tmp = 0;
	return (mem);
}
