
#include "../include/wolf3d.h"

void	valid2(t_st *e)
{
	int		i;
	int		j;

	i = 0;
	if (e->map_h < 3 || e->map_w < 3)
		invalid();
	while (i < e->map_h)
	{
		j = 0;
		if (e->map[i][0] < 1)
			invalid();
		if (e->map[i][e->map_w - 1] < 1)
			invalid();
		while (j < e->map_w)
		{
			if (e->map[0][j] < 1)
				invalid();
			if (e->map[e->map_h - 1][j] < 1)
				invalid();
			j++;
		}
		i++;
	}
}

void	invalid(void)
{
	ft_putstr("invalid map\n");
	exit(1);
}

void	valid(t_st *wolf, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	wolf->map_w = i;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (j != wolf->map_w)
				invalid();
			j = -1;
			wolf->map_h += 1;
		}
		j++;
		i++;
	}
}

void	transform_data(t_st *wolf, char *str, int i)
{
	int		j;
	int		w;

	j = 0;
	wolf->map = (int**)malloc(sizeof(int*) * (wolf->map_h));
	w = -1;
	while (++w < wolf->map_h)
		wolf->map[w] = (int*)malloc(sizeof(int) * wolf->map_w);
	w = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j = -1;
			w++;
		}
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
			invalid();
		if (str[i] >= '0' && str[i] <= '9')
		{
			wolf->map[w][j] = (int)(str[i] - 48);
		}
		i++;
		j++;
	}
}

void	ft_read(t_st *wolf, char *s)
{
	char	*buff;
	char	*temp;
	int		fd;

	buff = NULL;
	if ((fd = open(s, O_RDONLY)) < 0)
		ft_usage();
	temp = ft_strnew(1);
	while (get_next_line(fd, &buff) > 0)
	{
		temp = ft_strjoinfree(temp, buff, 3);
		temp = ft_strjoinfree(temp, "\n", 1);
	}
	valid(wolf, temp);
	transform_data(wolf, temp, 0);
	free(temp);
	valid2(wolf);
}