/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:25:39 by mbenjell          #+#    #+#             */
/*   Updated: 2017/02/14 18:23:57 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					new_file(int fd, int *start, t_save *s)
{
	*start = 1;
	s->fd = fd;
	s->buff_init = malloc(0);
	s->buff = NULL;
	s->p = NULL;
	s->nb = 0;
	s->fin = 1;
	s->mem = NULL;
	return (0);
}

int					read_line(t_save *s)
{
	if (!s->nb)
	{
		free(s->buff_init);
		if (!(s->buff = (char*)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		s->buff_init = s->buff;
		s->nb = read(s->fd, s->buff, BUFF_SIZE);
		if (s->nb == -1)
			return (-1);
		if (!s->nb)
			return (s->fin = 0);
	}
	return ((write_mem(s) == -1) ? -1 : s->fin);
}

int					write_mem(t_save *s)
{
	t_mem			*new;

	if (!(new = (t_mem*)malloc(sizeof(t_mem))))
		return (-1);
	if (!(s->p = ft_memchr((const void*)(s->buff), SEP, s->nb)))
	{
		new->next = s->mem;
		s->mem = new;
		(s->mem)->m = (char*)malloc(sizeof(char) * s->nb);
		ft_memcpy((void*)(s->mem)->m, (const void*)s->buff, s->nb);
		s->mem->nb = s->nb;
		s->nb = 0;
		s->fin = ((read_line(s) == -1) ? -1 : 1);
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
	}
	return (0);
}

int					write_line(t_mem *mem, char **line, int i)
{
	static int		j;

	if (mem)
	{
		if (write_line(mem->next, line, i + mem->nb) == -1)
			return (-1);
		ft_memcpy((void*)(*line + j), (const void*)mem->m, mem->nb);
		j += mem->nb;
		free(mem->m);
		free(mem);
	}
	else
	{
		if (!(*line = (char*)malloc(sizeof(char) * (i + 1))))
			return (-1);
		j = 0;
		*(*line + i) = END;
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_save	*s;
	static int		start = 0;
	static int		end = 0;
	static int		old_fd = -1;

	if (line == NULL || fd < 0)
		return (-1);
	if ((old_fd != fd) || !start)
	{
		if (!(s = (t_save*)malloc(sizeof(t_save))))
			return (-1);
		start = 0;
		end = 0;
		old_fd = fd;
	}
	if (end)
		return (0);
	if (!start)
		new_file(fd, &start, s);
	if (((s->i = read_line(s)) != -1) && (write_line(s->mem, line, 0) == -1))
		return (-1);
	if ((s->i == 0) && ft_strlen(*line) == 0)
		return (new_file(fd, &start, s));
	s->mem = NULL;
	return (s->i ? s->i : (end = 1));
}
