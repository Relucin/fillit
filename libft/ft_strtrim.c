/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 01:07:14 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 01:33:01 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int len;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return (ft_strdup(s));
	len = 0;
	while (s[len])
		len++;
	--len;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (ft_strsub(s, 0, len + 1));
}
