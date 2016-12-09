/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:54:03 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/04 19:49:53 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elt;

	if ((elt = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	elt->next = NULL;
	if (content == NULL)
	{
		elt->content_size = 0;
		elt->content = NULL;
		return (elt);
	}
	elt->content = ft_memalloc(content_size);
	if (!(elt->content))
		return (NULL);
	ft_memcpy(elt->content, content, content_size);
	elt->content_size = content_size;
	return (elt);
}
