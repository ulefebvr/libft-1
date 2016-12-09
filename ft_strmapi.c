/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:06:15 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 20:11:03 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	char	*p_init;
	int		i;

	if (!s || !f)
		return (NULL);
	p = ft_strnew(ft_strlen(s));
	p_init = p;
	i = 0;
	if (!p)
		return (NULL);
	while (*s)
		*p++ = f(i++, *s++);
	return (p_init);
}
