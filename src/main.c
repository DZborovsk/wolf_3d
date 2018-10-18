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

void	position(t_st *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->map_h)
	{
		j = 0;
		while (j < e->map_w)
		{
			if (e->map[i][j] == 0)
			{
				e->posx = j;
				e->posy = i;
				return ;
			}
			j++;
		}
		i++;
	}
	invalid();
}

void	ft_usage(void)
{
	ft_putendl("usage: ./wolf3d <map_name>");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_st *wolf;

	if (argc == 2)
	{
		wolf = malloc(sizeof(t_st));
		ft_read(wolf, argv[1]);
		wolf->mlx = mlx_init();
		position(wolf);
		system("afplay ./src/music.mp3 &");
		wolf->wind = mlx_new_window(wolf->mlx, WIDTH, HEIGHT, "wolf3d");
		wolf->img = mlx_new_image(wolf->mlx, WIDTH, HEIGHT);
		wolf->addr = mlx_get_data_addr(wolf->img,
			&(wolf->bits_per_pixel), &(wolf->size_line), &(wolf->endian));
		ft_init(wolf);
		le_hook(124, wolf);
		le_hook_help(wolf, 126);
		mlx_hook(wolf->wind, 17, 1L << 17, ft_esc, wolf);
		mlx_hook(wolf->wind, 2, 5, le_hook, wolf);
		mlx_loop(wolf->mlx);
	}
	else
		ft_usage();
	return (0);
}
