/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:17:37 by mbenjell          #+#    #+#             */
/*   Updated: 2016/11/28 20:22:36 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_init;

	dest_init = dest;
	while (n-- && *src)
		*dest++ = *src++;
	n++;
	while (n--)
		*dest++ = '\0';
	return (dest_init);
}
