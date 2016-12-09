/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:17:29 by mbenjell          #+#    #+#             */
/*   Updated: 2016/11/28 00:39:48 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	char *dest_init;

	dest_init = dest;
	while (*dest++)
		;
	dest--;
	while (*src && n--)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_init);
}
