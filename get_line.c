/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:19:34 by mbenjell          #+#    #+#             */
/*   Updated: 2017/05/04 13:25:56 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	new_buff(t_save *s)
{
	free(s->buff_init);
	if (!(s->buff = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	s->buff_init = s->buff;
	s->nb = read(s->fd, s->buff, BUFF_SIZE);
	if (s->nb == -1)
	{
		ft_strdel(&(s->buff_init));
		return (-1);
	}
	if (!s->nb)
	{
		ft_strdel(&(s->buff_init));
		return (0);
	}
	return (1);
}

int			begin_read(t_save *s, t_mem **new)
{
	int		r;

	if (s->j > MAX_ALLOC)
		return (-1);
	if (!(*new = (t_mem*)malloc(sizeof(t_mem))))
		return (-1);
	if (!s->nb)
	{
		r = new_buff(s);
		if (r == 0)
			return (0);
		if (r == -1)
			return (-1);
	}
	return (1);
}

int			nsearch(t_save *s, t_mem *new)
{
	if (!(s->p = ft_memchr((const void*)(s->buff), SEP, s->nb)))
	{
		new->next = s->mem;
		s->mem = new;
		(s->mem)->m = (char*)malloc(sizeof(char) * s->nb);
		ft_memcpy((void*)(s->mem)->m, (const void*)s->buff, s->nb);
		s->mem->nb = s->nb;
		s->nb = 0;
		s->j += s->mem->nb;
	}
	else
	{
		new->next = s->mem;
		s->mem = new;
		(s->mem)->m = (char*)malloc(sizeof(char) * s->nb);
		ft_memcpy((void*)(s->mem)->m, (const void*)(s->buff), s->p - s->buff);
		s->mem->nb = s->p - s->buff;
		s->nb -= s->p - s->buff + 1;
		s->buff += s->p - s->buff + 1;
		s->j += s->mem->nb;
		return (1);
	}
	return (0);
}

int			get_line(t_save *s)
{
	t_mem	*new;
	int		b;

	while (42)
	{
		b = begin_read(s, &new);
		if (b == 0)
			return (0);
		if (b == -1)
			return (-1);
		if (nsearch(s, new) == 1)
			return (1);
	}
	return (1);
}
