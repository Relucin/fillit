/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 23:46:25 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 01:17:50 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ns;
	char *hold;

	if (!(ns = (char*)malloc(ft_strlen(s) + 1)))
		return (0);
	hold = ns;
	while (*s)
		*ns++ = f(*s++);
	*ns = '\0';
	return (hold);
}
