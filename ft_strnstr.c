/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:47:18 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 16:14:37 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	int i;

	i = big[0];
	if (ft_strlen(little) == 0)
		return ((char*)big);
	if (n < ft_strlen(little))
		return (NULL);
	if (ft_strnequ(big, little, ft_strlen(little)))
		return ((char*)big);
	return ((*big && n) ? ft_strnstr(++big, little, --n) : NULL);
}
