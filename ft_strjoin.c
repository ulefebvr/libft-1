/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:12:41 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 20:15:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*p_init;
	int		n1;
	int		n2;

	if (!s1 || !s2)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	p = ft_memalloc(n1 + n2 + 1);
	if (!p)
		return (NULL);
	p_init = p;
	p = ft_memcpy((void*)p, (const void*)s1, n1);
	p += n1;
	p = ft_memcpy((void*)p, (const void*)s2, n2);
	p += n2;
	*p = '\0';
	return (p_init);
}
