/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzagura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:45:58 by gzagura           #+#    #+#             */
/*   Updated: 2018/03/24 20:46:00 by gzagura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static t_getlist		*ft_worklist(t_getlist *wolf, int fd)
{
	if (wolf == NULL)
	{
		wolf = (t_getlist*)malloc(sizeof(t_getlist));
		wolf->next = NULL;
		wolf->content = ft_strnew(BUFF_SIZE);
		wolf->num_fd = fd;
		return (wolf);
	}
	while (wolf != NULL)
	{
		if (wolf->num_fd == fd)
			return (wolf);
		else if (wolf->next)
			wolf = wolf->next;
		else
			break ;
	}
	wolf->next = (t_getlist*)malloc(sizeof(t_getlist));
	wolf->next->next = NULL;
	wolf->next->content = ft_strnew(BUFF_SIZE);
	wolf->next->num_fd = fd;
	return (wolf->next);
}

static int				ft_wortstr(t_getlist *wolf, int bytes, char **line)
{
	char	*temp;

	if (ft_strchr(wolf->content, '\n'))
	{
		*line = ft_strsub(wolf->content, 0,
			(int)(ft_strchr(wolf->content, '\n') - wolf->content));
		temp = ft_strdup(ft_strchr(wolf->content, '\n') + 1);
		free(wolf->content);
		wolf->content = ft_strdup(temp);
		free(temp);
		return (1);
	}
	if (wolf->content[0] != '\0' && bytes < BUFF_SIZE)
	{
		*line = ft_strdup(wolf->content);
		ft_bzero(wolf->content, ft_strlen(wolf->content));
		return (1);
	}
	if (wolf->content[0] != '\0')
		return (-1);
	return (0);
}

static int				ft_crazy(char *buffe, int fd, char **line, int bytes)
{
	static t_getlist	*tmp = NULL;
	t_getlist			*wolf;

	*line = NULL;
	if (!tmp)
	{
		tmp = ft_worklist(tmp, fd);
		wolf = tmp;
	}
	else
		wolf = ft_worklist(tmp, fd);
	*line = ft_strjoin(wolf->content, buffe);
	free(wolf->content);
	wolf->content = ft_strdup(*line);
	free(*line);
	return (ft_wortstr(wolf, bytes, line));
}

int						get_next_line(const int fd, char **line)
{
	int		bytes;
	int		re;
	char	buffe[BUFF_SIZE + 1];

	buffe[BUFF_SIZE] = '\0';
	if (!line || fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	while ((bytes = read(fd, buffe, BUFF_SIZE)) > -2)
	{
		if (bytes == -1)
			return (-1);
		if (bytes < BUFF_SIZE)
			ft_bzero((void **)(buffe + bytes), BUFF_SIZE - bytes);
		while ((re = ft_crazy(buffe, fd, line, bytes)) > -2)
		{
			if (re == -1)
				break ;
			return (re);
		}
	}
	return (0);
}
