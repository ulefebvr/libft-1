/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:08:21 by mbenjell          #+#    #+#             */
/*   Updated: 2016/11/29 02:22:56 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*s_init;
	int		n;

	s_init = (char*)s;
	n = ft_strlen(s);
	while (n--)
		s++;
	while (*s != (char)c && s != s_init)
		s--;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
