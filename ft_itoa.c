/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:03:23 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/06 03:10:18 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_pnbr(char *p, int i, int n)
{
	if (n == -2147483648)
		ft_strcpy(p, "-2147483648");
	if (n == 0)
		ft_strcpy(p, "0");
	if (n > -2147483648)
	{
		while (n)
		{
			p[i--] = n % 10 + '0';
			n /= 10;
		}
	}
}

char			*ft_itoa(int n)
{
	char		*p;
	int			i;
	int			nb;

	i = 0;
	nb = n;
	while (n /= 10)
		i++;
	if (nb < 0)
	{
		p = ft_strnew((size_t)(++i + 1));
		if (!p)
			return (NULL);
		*p = '-';
		nb = ABS(nb);
	}
	else
	{
		p = ft_strnew((size_t)(i + 1));
		if (!p)
			return (NULL);
	}
	ft_pnbr(p, i, nb);
	return (p);
}
