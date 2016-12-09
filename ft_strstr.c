/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:17:45 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 16:14:30 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int i;

	i = big[0];
	if (ft_strlen(little) == 0)
		return ((char*)big);
	if (ft_strnequ(big, little, ft_strlen(little)))
		return ((char*)big);
	return (*big ? ft_strstr(++big, little) : NULL);
}
