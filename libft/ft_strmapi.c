/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 23:46:25 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 01:18:36 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ns;

	if (!(ns = (char*)malloc(ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (*s)
	{
		ns[i] = f(i, *s++);
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
