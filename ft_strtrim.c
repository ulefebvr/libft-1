/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:24:01 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 16:26:31 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j])
		j++;
	j--;
	if (j == i - 1)
		return (ft_strnew(0));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	p = ft_strsub(s, i, (size_t)(j - i + 1));
	return (!p ? NULL : p);
}
