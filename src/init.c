#include "../include/wolf3d.h"

static void	ft_texture_init(t_st *wolf)
{
	wolf->t[0].addr = mlx_get_data_addr(wolf->t[0].img,
		&wolf->t[0].bpp, &wolf->t[0].sl, &wolf->t[0].endl);
	wolf->t[1].addr = mlx_get_data_addr(wolf->t[1].img,
		&wolf->t[1].bpp, &wolf->t[1].sl, &wolf->t[1].endl);
	wolf->t[2].addr = mlx_get_data_addr(wolf->t[2].img,
		&wolf->t[2].bpp, &wolf->t[2].sl, &wolf->t[2].endl);
	wolf->t[3].addr = mlx_get_data_addr(wolf->t[3].img,
		&wolf->t[3].bpp, &wolf->t[3].sl, &wolf->t[3].endl);
	wolf->t[4].addr = mlx_get_data_addr(wolf->t[4].img,
		&wolf->t[4].bpp, &wolf->t[4].sl, &wolf->t[4].endl);
	wolf->t[5].addr = mlx_get_data_addr(wolf->t[5].img,
		&wolf->t[5].bpp, &wolf->t[5].sl, &wolf->t[5].endl);
}

void	ft_init(t_st *wolf)
{
	int		lar;
	int		lon;

	wolf->planex = 0;
	wolf->planey = 0.66;
	wolf->dirx = 1;
	wolf->diry = 0;
	wolf->move = 0.32;
	wolf->music = 1;
	wolf->rot = 0.09;
	wolf->t[0].img = mlx_xpm_file_to_image(wolf->mlx,
		"./img/grey_stone.xpm", &lar, &lon);
	wolf->t[1].img = mlx_xpm_file_to_image(wolf->mlx,
		"./img/eagle.xpm", &lar, &lon);
	wolf->t[2].img = mlx_xpm_file_to_image(wolf->mlx,
		"./img/blue_stone.xpm", &lar, &lon);
	wolf->t[5].img = mlx_xpm_file_to_image(wolf->mlx,
		"./img/color_stone.xpm", &lar, &lon);
	wolf->t[4].img = mlx_xpm_file_to_image(wolf->mlx,
		"./img/purple_stone.xpm", &lar, &lon);
	wolf->t[3].img = mlx_xpm_file_to_image(wolf->mlx,
		"./img/red_brick.xpm", &lar, &lon);
	ft_texture_init(wolf);
}