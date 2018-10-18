/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:43:04 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 12:10:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define HEIGHT 850
# define WIDTH 850
# define TT 64

typedef struct			s_rgb
{
	int					b;
	int					g;
	int					r;
	int					col;
}						t_rgb;

typedef struct			s_images
{
	int					bpp;
	int					endl;
	int					sl;
	char				*addr;
	void				*img;
}						t_img;

typedef struct			s_wolf
{
	t_img				t[6];
	int					texx;
	int					texy;
	int					lineheight;
	double				wallx;
	double				camx;
	double				camy;
	double				floor_x;
	double				floor_y;
	void				*mlx;
	void				*wind;
	int					**map;
	double				planex;
	double				planey;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				camerax;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	int					side;
	int					hit;
	int					stepx;
	int					stepy;
	int					drawstart;
	int					drawend;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				walld;
	double				move;
	double				rot;
	int					tetx;
	int					tety;
	int					tmp;
	int					map_w;
	int					map_h;
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	void				*img;
	t_rgb				rgb;
	int 				music;
}						t_st;

void					ft_init(t_st *wolf);
void					ft_read(t_st *wolf, char *str);
void					verline(t_st *e, int x);
void					draw_floor(t_st *e, int x);
int						le_hook(int key, t_st *e);
int						pixels(int x, int y);
void					invalid(void);
char					*ft_strjoinfree(const char *s1, const char *s2, int n);
int						ft_esc(t_st *wolf);
void					ft_usage(void);
void					le_hook_help(t_st *e, int key);
void					tata(t_st *wolf);
void					draw(t_st *e);

#endif
