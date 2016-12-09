/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:17:05 by mbenjell          #+#    #+#             */
/*   Updated: 2016/11/22 13:50:38 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	char *dest_init;

	dest_init = dest;
	while (*dest++)
		;
	dest--;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_init);
}
