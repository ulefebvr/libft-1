/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 00:29:09 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 20:10:10 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	char	*p_init;

	if (!s || !f)
		return (NULL);
	p = ft_strnew(ft_strlen(s));
	p_init = p;
	if (!p)
		return (NULL);
	while (*s)
		*p++ = f(*s++);
	return (p_init);
}
