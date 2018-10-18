#include "../include/wolf3d.h"

int		le_hook(int key, t_st *e)
{
	double olddirx;
	double oldplanex;

	if (key == 53)
		ft_esc(e);
	if (key == 123)
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(-(e->rot)) - e->diry * sin(-(e->rot));
		e->diry = olddirx * sin(-(e->rot)) + e->diry * cos(-(e->rot));
		oldplanex = e->planex;
		e->planex = e->planex * cos(-(e->rot)) - e->planey * sin(-(e->rot));
		e->planey = oldplanex * sin(-(e->rot)) + e->planey * cos(-(e->rot));
	}
	if (key == 124)
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(e->rot) - e->diry * sin(e->rot);
		e->diry = olddirx * sin(e->rot) + e->diry * cos(e->rot);
		oldplanex = e->planex;
		e->planex = e->planex * cos(e->rot) - e->planey * sin(e->rot);
		e->planey = oldplanex * sin(e->rot) + e->planey * cos(e->rot);
	}
	le_hook_help(e, key);
	return (0);
}

void	le_hook_help(t_st *e, int key)
{
	if (key == 46 && e->music == 1)
	{
		system("killall afplay");
		e->music = 0;
	}
	else if (key == 46 && e->music == 0)
	{
		system("afplay ./src/music.mp3 &");
		e->music = 1;
	}
	if (key == 126)
	{
		if (e->map[(int)(e->posx + e->dirx * (e->move + 0.2))][(int)(e->posy)] == 0)
			e->posx += e->dirx * e->move;
		if (e->map[(int)(e->posx)][(int)(e->posy + e->diry * (e->move + 0.2))] == 0)
			e->posy += e->diry * e->move;
	}
	if (key == 125)
	{
		if (e->map[(int)(e->posx - e->dirx * (e->move + 0.2))][(int)(e->posy)] == 0)
			e->posx -= e->dirx * e->move;
		if (e->map[(int)(e->posx)][(int)(e->posy - e->diry * (e->move + 0.2))] == 0)
			e->posy -= e->diry * e->move;
	}
	tata(e);
}

int		ft_esc(t_st *wolf)
{
	ft_putstr("Bye-bye\n");
	mlx_destroy_window(wolf->mlx, wolf->wind);
	system("killall afplay");
	exit(0);
	return (0);
}

char	*ft_strjoinfree(const char *s1, const char *s2, int n)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return ((!s1) ? (char*)s2 : (char*)s1);
	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = -1;
	while ((char)s1[++i] != '\0')
		s[i] = (char)s1[i];
	j = -1;
	while ((char)s2[++j] != '\0')
		s[i++] = (char)s2[j];
	if (n == 1 || n == 2)
		free((n == 1) ? (char*)s1 : (char*)s2);
	else if (n == 3)
	{
		free((char*)s1);
		free((char*)s2);
	}
	return (s);
}
