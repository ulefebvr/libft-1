/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 03:22:43 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/04 19:55:10 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;

	p = (t_list*)ft_memalloc(sizeof(f(lst)));
	if (lst != NULL)
	{
		p = f(lst);
		p->next = ft_lstmap(lst->next, f);
	}
	if (lst == NULL)
		return (NULL);
	return (p);
}
