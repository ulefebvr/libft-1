/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:26:25 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 20:13:59 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	while (start--)
		s++;
	p = ft_memalloc(len + 1);
	return (!p ? NULL : ft_strncpy(p, s, len));
}
