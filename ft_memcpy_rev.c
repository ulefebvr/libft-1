/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 01:19:28 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/04 23:07:26 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	void *p_init;

	p_init = dest;
	while (n--)
		((t_oct*)dest)[n] = ((t_oct*)src)[n];
	return (p_init);
}
