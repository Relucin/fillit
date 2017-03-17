/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:01:05 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/14 00:54:50 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ntl;

	if (!(ntl = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(ntl->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(ntl->content, content, content_size);
		ntl->content_size = content_size;
	}
	else
	{
		ntl->content = NULL;
		ntl->content_size = 0;
	}
	ntl->next = NULL;
	return (ntl);
}
