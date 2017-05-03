/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:25:39 by mbenjell          #+#    #+#             */
/*   Updated: 2017/05/03 17:02:59 by mbenjell         ###   ########.fr       */
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

int					write_line(t_mem *mem, char **line, size_t *j)
{
	t_mem *temp;

	*line = (char*)ft_memalloc(sizeof(char) * (*j + 1));
	*line += *j;
	**line = END;
	while (mem)
	{
		ft_memcpy((void*)(*line -= mem->nb), (const void*)(mem->m), mem->nb);
		temp = mem;
		mem = mem->next;
		free(temp->m);
		free(temp);
	}
	*j = 0;
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
	if (((s->i = get_line(s)) != -1) && (write_line(s->mem, line, &s->j) == -1))
		return (-1);
	if ((s->i == 0) && ft_strlen(*line) == 0)
		return (new_file(fd, &start, s));
	s->mem = NULL;
	return (s->i ? s->i : (end = 1));
}
