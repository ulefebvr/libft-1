/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:26:51 by mbenjell          #+#    #+#             */
/*   Updated: 2017/05/17 23:27:09 by mbenjell         ###   ########.fr       */
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
	char		*temp;

	while (len--)
	{
		i = 0;
		temp = chaine;
		chaine = ft_strctrim((char const*)chaine, c);
		free(temp);
		*tab = ft_strsub(chaine, 0, len_first_word(chaine, c) + 1);
		temp = *tab;
		*tab = ft_strctrim((char const*)(*tab), c);
		free(temp);
		while (len > 0 && (chaine[i] != c && chaine[i] != '\0'))
			i++;
		temp = chaine;
		chaine = ft_strsub(chaine, i, ft_strlen(chaine) - i);
		free(temp);
		if (len < 1)
		{
			free(chaine);
			break ;
		}
		tab++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char		*chaine;
	int			len;
	char		**tab;
	char		**tab_init;
	char		*temp;

	if (!s)
		return (NULL);
	chaine = ft_memalloc(ft_strlen(s) + 1);
	if (!chaine)
		return (NULL);
	ft_strcpy(chaine, temp = ft_strctrim(s, c));
	free(temp);
	len = nb_word(chaine, c);
	tab = (char**)ft_memalloc(sizeof(char*) * (len + 1));
	if (!tab)
	{
		free(chaine);
		return (NULL);
	}
	tab_init = tab;
	if (ft_strlen(temp = ft_strctrim((const char*)chaine, c)) == 0)
	{
		free(temp);
		*tab = NULL;
		return (tab);
	}
	ft_extend(tab, len, chaine, c);
	return (!tab_init ? NULL : tab_init);
}
