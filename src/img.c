#include "../include/wolf3d.h"

int		pixels(int x, int y)
{
	int		count_pix;

	count_pix = 0;
	count_pix = (x * 4) + ((WIDTH * 4) * y);
	return (count_pix);
}

void	wrip(t_st *wolf, int count_pxl)
{
	wolf->addr[count_pxl] = wolf->rgb.col & 0x0000ff;
	wolf->addr[count_pxl + 1] = (wolf->rgb.col >> 8) & 0xff;
	wolf->addr[count_pxl + 2] = (wolf->rgb.col >> 16);
}

void	verline(t_st *e, int x)
{
	int y;
	int i;

	e->camx = e->dirx + e->planex * e->camerax;
	e->camy = e->diry + e->planey * e->camerax;
	y = e->drawstart - 1;
	if (e->side == 0 && e->camx >= 0)
		i = 0;
	else if (e->side == 0 && e->camx < 0)
		i = 1;
	else if (e->side == 1 && e->camy >= 0)
		i = 2;
	else
		i = 3;
	while (++y < e->drawend)
	{
		e->tmp = y * 256 - HEIGHT * 128 + e->lineheight * 128;
		e->texy = ((e->tmp * 64) / e->lineheight) / 256;
		e->rgb.col = e->t[i].addr[e->texx * 4 + e->texy * e->t[i].sl + 2] << 16;
		e->rgb.col += e->t[i].addr[e->texx * 4 + e->texy * e->t[i].sl + 1] << 8;
		e->rgb.col += e->t[i].addr[e->texx * 4 + e->texy * e->t[i].sl];
		if (e->side == 1)
			e->rgb.col = (e->rgb.col >> 1) & 8355711;
		wrip(e, pixels(x, y));
	}
}
