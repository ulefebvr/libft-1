/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:26:51 by mbenjell          #+#    #+#             */
/*   Updated: 2016/12/05 20:17:06 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_word(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i + 1])
	{
		if (s[i] != c && s[i + 1] == c)
			j++;
		i++;
	}
	return (++j);
}

static size_t	len_first_word(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (*s++ != c && *s)
		i++;
	return (i);
}

static char		*ft_strctrim(char const *s, char c)
{
	char		*p;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[j])
		j++;
	j--;
	if (j == i - 1)
		return (ft_strnew(0));
	while (s[j] == c)
		j--;
	p = ft_strsub(s, i, (size_t)(j - i + 1));
	return (!p ? NULL : p);
}

static void		ft_extend(char **tab, int len, char *chaine, char c)
{
	int			i;

	while (len--)
	{
		i = 0;
		chaine = ft_strctrim((char const*)chaine, c);
		*tab = ft_strsub(chaine, 0, len_first_word(chaine, c) + 1);
		*tab = ft_strctrim((char const*)(*tab), c);
		while (len > 0 && (chaine[i] != c && chaine[i] != '\0'))
			i++;
		chaine = ft_strsub(chaine, i, ft_strlen(chaine) - i);
		if (len < 1)
			break ;
		tab++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char		*chaine;
	int			len;
	char		**tab;
	char		**tab_init;

	if (!s)
		return (NULL);
	chaine = ft_memalloc(ft_strlen(s) + 1);
	if (!chaine)
		return (NULL);
	ft_strcpy(chaine, ft_strctrim(s, c));
	len = nb_word(chaine, c);
	tab = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	if (!tab)
		return (NULL);
	tab_init = tab;
	if (ft_strlen(ft_strctrim((const char*)chaine, c)) == 0)
	{
		*tab = NULL;
		return (tab);
	}
	ft_extend(tab, len, chaine, c);
	return (!tab_init ? NULL : tab_init);
}
