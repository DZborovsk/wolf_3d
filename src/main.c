/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:58:00 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 12:13:55 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int 	ft_count_w(char *s)
{
	int 	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int 	ft_count_nl(char *s)
{
	int 	i;
	int 	nl;

	nl = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			nl++;
		i++;
	}
	return (nl);
}

char 	*ft_read(int fd)
{
	int 	rd;
	char	buff[BUFF_SIZE + 1];
	char 	*s;
	char 	*tmp;

	s = ft_strdup("");
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		free(tmp);
	}
	return (s);
}

void			ft_open(t_st *wolf, char *file)
{
	int		fd;
	char	**array;
	int 	y;
	char 	*s;
	int 	nl;
	int 	i;
	int 	width;
	int 	k;

	nl = 0;
	y = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("Open file fail (Error -1)");
		free(wolf);
		exit(0);
	}
	s = ft_read(fd);
//	ft_putstr(s);
	nl = ft_count_nl(s);
//	ft_putnbr(nl);
	array = (char**)malloc(sizeof(char*) * (nl + 1));
	array[nl] = NULL;
//	ft_putstr(s);
	width = ft_count_w(s);
//	ft_putnbr(width);
	k = 0;
	while (nl > y)
	{
		i = 0;
		array[y] = (char*)malloc(sizeof(char) * (width));
		while (s[k] && s[k] != '\n')
		{
			array[y][i] = s[k];
			i++;
			k++;
		}
		array[y][i] = '\0';
		if (s[k] == '\n')
			k++;
		y++;
	}
	wolf->map = array;
/*	ft_putendl(array[0]);
	ft_putendl(array[1]);
	ft_putendl(array[2]);
	ft_putendl(array[3]);
	ft_putendl(array[4]);
	ft_putendl(array[5]);*/
}

t_st	*ft_init(void)
{
	t_st	*wolf;

	wolf = (t_st*)malloc(sizeof(t_st));
	return (wolf);
}

int		main(int ac, char **av)
{
	t_st	*wolf;

	if (ac != 2)
	{
		ft_putendl("usage: ./wolf3d <map_name>");
		return (1);
	}
	wolf = ft_init();
	if (ac == 2 && av[1])
	{
		ft_open(wolf, av[1]);

	}
	return (0);
}
