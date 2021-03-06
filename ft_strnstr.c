/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:47:18 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/20 17:21:55 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	if (ft_strlen(little) == 0)
		return ((char*)big);
	if (n < ft_strlen(little))
		return (NULL);
	if (ft_strnequ(big, little, ft_strlen(little)))
		return ((char*)big);
	return ((*big && n) ? ft_strnstr(++big, little, --n) : NULL);
}
