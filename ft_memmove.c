/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:03:39 by mbenjell          #+#    #+#             */
/*   Updated: 2016/11/29 01:40:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((dest == src) || !n)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	return (ft_memcpy_rev(dest, src, n));
}
