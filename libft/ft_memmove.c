/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:12:47 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/03 14:15:48 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char*)(dst + n - 1);
	s = (char*)(src + n - 1);
	if (src > dst)
		return (ft_memcpy(dst, src, n));
	while (n)
	{
		*d-- = *s--;
		n--;
	}
	return (dst);
}
