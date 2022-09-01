/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:14:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/02 00:31:05 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "/Users/Romain/Desktop/propro/cub3dbizarrequipete/Cub3d/libft/includes/libft.h"

void	ft_freetabb(u_int32_t**tab)
{
	int	i;

	i = 0;
	while (i < 1080)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}

float degToRad(int a) { return a*M_PI/180.0;}

float	dist(float ax, float ay, float bx, float by, float ang)
{
	return (   sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)));	
}

int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_image *data, int beginx, int beginy, int endx, int endy, int color)
{
	float	deltax;
	float	deltay;
	float	pixelx;
	float	pixely;
	int		pixels;



	pixelx = beginx;
	pixely = beginy;
	deltax = endx - beginx;
	deltay = endy - beginy ;
	pixels = sqrt((deltax * deltax)
			+ (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = beginx;
	pixely = beginy;
	// if (pixelx > 1000)
	// 	pixelx = 1000;
	// if (pixely > 1000)
	// 	pixely = 1000;
	
	while (pixels) //&& pixelx > 0 && pixely > 0 && pixelx < 1000 && pixely < 1000
	{
		if (color == 2)
			my_mlx_pixel_put(data, pixelx, pixely, 0xff0000);
		else if (color == 1)
			my_mlx_pixel_put(data, pixelx, pixely, 0xfffe00);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return ;
}

u_int32_t**	ft_mem2array(uint32_t *mem, size_t len_x, size_t len_y)
{
	u_int32_t	**arr;
	size_t		i;

	arr = malloc(len_y * sizeof(u_int32_t*));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_y)
	{
		arr[i] = &(mem[i * len_x]);
		++i;
	}
	return (arr);
}

void	ft_drawwalls(t_cub *cub, int beginx, int beginy, int lineH, int dir)
{
	int x;
	int y;

	x = beginx;
	while (x < beginx + 8)				
	{
		y = beginy - lineH;
		while ( y < beginy + lineH )
		{
			if (x > 0 && y > 0 && x < 1920 && y < 1080)
			{
				if (dir == 1)
					cub->image[0].arr[y++][x] = 0xffff00;
				else
					cub->image[0].arr[y++][x] = 0xff1100;
			}
			else
				y++;
			
		}
		x++;
	}

}

void	drawrays(t_cub *cub)
{

//	char tmp;
	int map[]=
	{
		1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
	};
	
	int r,mx,my,mp,dof;      // ra player angle temporaire ; aTan nTan
	int dir;
	int x;
	int y;
	dir = 1;
	x = 0;
	y = 0;
	while (y < 1080)
	{
		int x = 0;
		while (x < 1920)
		{
			
				cub->image[0].arr[y][x++] = 0x000000;
			
		}
		++y;
	}
	cub->data.ra = cub->pos.pa - DR * 30;
	if (cub->data.ra < 0)
		cub->data.ra += 2 * PI;
	if (cub->data.ra > 2 * PI)
		cub->data.ra -= 2 * PI;
	for (r = 0; r < 60; r++)
	{
		dir = 1;
	// P1
		dof = 0;
		cub->data.disH = 1000000;
		cub->data.horix = cub->pos.x;
		cub->data.horiy = cub->pos.y;
		cub->data.aTan = -1/tan(cub->data.ra);
		if (cub->data.ra > PI){
			cub->data.rayY = (((int)cub->pos.y>>6)<<6) - 0.0001;
			cub->data.rayX = (cub->pos.y - cub->data.rayY) * cub->data.aTan + cub->pos.x;
			cub->data.yo = -64;
			cub->data.xo = -cub->data.yo * cub->data.aTan;
		//	tmp = 'n';// N
		}
		if (cub->data.ra < PI){
			cub->data.rayY = (((int)cub->pos.y>>6)<<6) + 64;
			cub->data.rayX = (cub->pos.y - cub->data.rayY) * cub->data.aTan + cub->pos.x;
			cub->data.yo = 64;
			cub->data.xo = -cub->data.yo * cub->data.aTan;
		}
		if (cub->data.ra == 0 || cub->data.ra == PI)
		{
			cub->data.rayX = cub->pos.x;
			cub->data.rayY = cub->pos.y;
			dof = 8;
		//	tmp = 's';// S
		}
		while (dof < 8)
		{
			mx = (int)(cub->data.rayX)>>6;
			my = (int)(cub->data.rayY)>>6;
			mp = my * cub->mapW + mx;
			if(mp > 0 && mp < cub->mapW * cub->mapH && map[mp] == 1)
			{
				cub->data.horix = cub->data.rayX;
				cub->data.horiy = cub->data.rayY;
				cub->data.disH = dist(cub->pos.x, cub->pos.y, cub->data.horix, cub->data.horiy, cub->data.ra);
				dof=8;
			}//hit
			else
			{
				cub->data.rayX += cub->data.xo;
				cub->data.rayY += cub->data.yo;
				dof += 1;
			}   
		}
		







	//P2		
		dof = 0;
		cub->data.disV = 1000000;
		cub->data.vertx = cub->pos.x;
		cub->data.verty = cub->pos.y;
		cub->data.nTan = -tan(cub->data.ra);
		if (cub->data.ra > PI2 && cub->data.ra < PI3){
			cub->data.rayX = (((int)cub->pos.x>>6)<<6) - 0.0001;
			cub->data.rayY = (cub->pos.x - cub->data.rayX) * cub->data.nTan + cub->pos.y;
			cub->data.xo = -64;
			cub->data.yo = -cub->data.xo * cub->data.nTan;
			//cub->data.dir = 'w';// W
		}
		if (cub->data.ra < PI2 || cub->data.ra > PI3){
			cub->data.rayX = (((int)cub->pos.x>>6)<<6) + 64;
			cub->data.rayY = (cub->pos.x - cub->data.rayX) * cub->data.nTan + cub->pos.y;
			cub->data.xo = 64;
			cub->data.yo = -cub->data.xo * cub->data.nTan;
			//cub->data.dir = 'e';// E
		}
		if (cub->data.ra == 0 || cub->data.ra == PI)
		{
			cub->data.rayX = cub->pos.x;
			cub->data.rayY = cub->pos.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx=(int)(cub->data.rayX)>>6;
			my=(int)(cub->data.rayY)>>6;
			mp = my * cub->mapW + mx;
			if(mp > 0 && mp < cub->mapW * cub->mapH && map[mp]==1)
			{
				cub->data.vertx = cub->data.rayX;
				cub->data.verty = cub->data.rayY;
				cub->data.disV = dist(cub->pos.x, cub->pos.y, cub->data.vertx, cub->data.verty, cub->data.ra);
				dof=8;
				}//hit
			else
			{
				cub->data.rayX += cub->data.xo;
				cub->data.rayY += cub->data.yo;
				dof+=1;
			}  
		}

		
		if (cub->data.disV > cub->data.disH)
		{
			dir = 1;
			cub->data.rayX = cub->data.horix;
			cub->data.rayY = cub->data.horiy;
			cub->data.disT = cub->data.disH;
		}
		if (cub->data.disV < cub->data.disH)
		{
			dir = 2;
			cub->data.rayX = cub->data.vertx;
			cub->data.rayY = cub->data.verty;
			cub->data.disT = cub->data.disV;
		}
		ft_draw_line(&cub->image[1], cub->pos.x, cub->pos.y, cub->data.rayX, cub->data.rayY, 2);
	
		cub->data.ca = cub->pos.pa - cub->data.ra;
		if (cub->data.ca < 0)
			cub->data.ca += 2 * PI;
		if (cub->data.ca > 2 * PI)
			cub->data.ca -= 2 * PI;
		cub->data.disT = cub->data.disT * cos(cub->data.ca);
		cub->data.lineH = (cub->mapScale * 500) / cub->data.disT;
		if (cub->data.lineH > 500)
			cub->data.lineH = 500;
		cub->data.lineO = 300 - cub->data.lineH / 2;
		
		ft_drawwalls(cub, r * 8 + 1000, cub->data.lineO , cub->data.lineH, dir);
 		cub->data.ra += DR;
		if (cub->data.ra < 0)
			cub->data.ra += 2 * PI;
		if (cub->data.ra > 2 * PI)
			cub->data.ra -= 2 * PI;
	}
}

void ft_putplayer(uint32_t**	img_color, t_pos *pos) // petit carre avec direction grace a un point
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1080)
	{
		int x = 0;
		while (x < 1920)
		{
			if (y >= pos->y  - 2 && y <= pos->y + 2 && x >= pos->x -2 && x <= pos->x + 2)
				img_color[y][x++] = 0xff0000;
			else
				x++;
		}
		++y;
	}
	// ft_draw_line(data, posx, posy, data->x + data->pdx * 5, data->y + data->pdy * 5);   // point directionnel sur minimap direction 
}

void ft_drawsquare(uint32_t**	img_color, int posx, int posy, int scale, int color) // pour la map pr l instant
{
	int x;
	int	y;

	x = posx;
	y = posy;
	while (y < 1080)
	{
		x = posx;
		while (x < 1920)
		{
			if (y <= posy + scale   && x <= posx + scale)
				img_color[y][x++] = 0xF3F3F2;
			else
				img_color[y][x++] = 0xFF000000;
		}
		++y;
	}
}

void ft_drawmap(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	y = 0;
	while (y < cub->mapH)
	 {
		x = 0;
		while (x < cub->mapW)
		{
			cub->xo = x * cub->mapScale ;
			cub->yo = y * cub->mapScale;
			if(cub->map[ y * cub->mapW + x] == 1)
			{
				ft_drawsquare(cub->image[1].arr, cub->xo, cub->yo, 64, 0x858485);
			}
			x++;
		}
		y++;
	}
	ft_putplayer(cub->image[1].arr, &cub->pos);
}

void	draw_font(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	uint32_t**	img_color = ft_mem2array((uint32_t*)cub->image[2].addr, 1920, 1080);
	while (y < 1080)
	{
		int x = 0;
		while (x < 1920)
		{
			if (y >= 540)
				img_color[y][x++] = 0x003300;
			else
				img_color[y][x++] = 0x000033;
		}
		++y;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image[2].img, 0, 0);
}

int	render_next_frame(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlxwin);

	ft_drawmap(cub);

	drawrays(cub);

	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image[0].img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image[1].img, 0, 0);
	return (0);
};

int	key_hook(int keycode, t_cub *cub)  // direction et gauche droite
{
	if (keycode == 53)
	{
		//ft_freetabb(cub->image[0].arr);
		exit (0);
	}
	if (keycode == 13)
	{
		cub->pos.x += cub->pos.pdx ;
		cub->pos.y += cub->pos.pdy ;
	}
	if (keycode == 2)
	{
		cub->pos.pa += 0.1;
		if(cub->pos.pa > 2 * PI)
			cub->pos.pa -= 2 * PI;
		cub->pos.pdx = cos(cub->pos.pa) * 5;
		cub->pos.pdy = sin(cub->pos.pa) * 5;
	}
	if (keycode == 1)
	{
		cub->pos.x -= cub->pos.pdx;
		cub->pos.y -= cub->pos.pdy ;
	}
	if (keycode == 0)
	{
		cub->pos.pa -= 0.1;
		if(cub->pos.pa < 0)
			cub->pos.pa += 2 * PI;
		cub->pos.pdx = cos(cub->pos.pa) * 5;
		cub->pos.pdy = sin(cub->pos.pa) * 5;
	}
	if (cub->pos.x > 1920)
		cub->pos.x = 0;
	if (cub->pos.x < 0)
		cub->pos.x = 1920;
	if (cub->pos.y > 1080)
		cub->pos.y = 0;
	if (cub->pos.y < 0)
		cub->pos.y = 1080;
	return (0);
}







void	init(t_cub *cub)
{

	//the map array. Edit to change level but keep the outer walls
	
	

	cub->mapW = 8;              							// a extraire
	cub->mapH = 8;
	cub->mapScale = 64;

//	cub->pos = ft_memalloc(sizeof(t_pos));

//	ft_bzero(&cub->pos, sizeof(t_pos));
	

	
	// cub->mlx = mlx_init();
	// cub->mlxwin = mlx_new_window(cub->mlx, 1920, 1080, "Cub3D");
	
	// cub->image[0]->img = mlx_new_image(cub->mlx, 1920, 1080);
	// cub->image[1]->img = mlx_new_image(cub->mlx, 1920, 1080);
	// cub->image[2]->img = mlx_new_image(cub->mlx, 1920, 1080);
	// cub->image[0]->addr = mlx_get_data_addr(cub->image[0]->img, &cub->image[0]->bits_per_pixel, &cub->image[0]->line_length,
	// 		&cub->image[0]->endian);
	// cub->image[1]->addr = mlx_get_data_addr(cub->image[0]->img, &cub->image[1]->bits_per_pixel, &cub->image[0]->line_length,
	// 		&cub->image[0]->endian);
	// cub->image[2]->addr = mlx_get_data_addr(cub->image[0]->img, &cub->image[2]->bits_per_pixel, &cub->image[0]->line_length,
	// 		&cub->image[0]->endian);
	// int i = 0;
	// while (i < 64)
	// {
	// 	cub->map[i] = map[i];
	// 	i++;
	// }
	
}

int main()
{
	t_cub	cub;
	t_raycasting r;

	//ft_bzero((void *)&r, sizeof(t_raycasting));



	init(&cub);
	cub.mlx = mlx_init();
	cub.mlxwin = mlx_new_window(cub.mlx, 1920, 1080, "Cub3D");
	
	cub.pos.x = 300;
	cub.pos.y = 300;
	cub.pos.pa = 0;
	
	cub.pos.pdx = cos(cub.pos.pa) * 5;
	cub.pos.pdy = sin(cub.pos.pa) * 5;

	int	map[] =         //the map array. Edit to change level but keep the outer walls
	{
		1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,1,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
	};

	int i = 0;
	while (i < 64){
		cub.map[i] = map[i];
		i++;
	}

	cub.image[0].img = mlx_new_image(cub.mlx, 1920, 1080);
	cub.image[1].img = mlx_new_image(cub.mlx, 1920, 1080);

	cub.image[0].addr = mlx_get_data_addr(cub.image[0].img, &cub.image[0].bits_per_pixel, &cub.image[0].line_length,
			&cub.image[0].endian);
	cub.image[0].arr = ft_mem2array((uint32_t*)cub.image[0].addr, 1920, 1080);
	
	cub.image[1].addr = mlx_get_data_addr(cub.image[1].img, &cub.image[1].bits_per_pixel, &cub.image[1].line_length,
			&cub.image[1].endian);
	cub.image[1].arr = ft_mem2array((uint32_t*)cub.image[1].addr, 1920, 1080);

	mlx_hook(cub.mlxwin, 2, 1L<<0, key_hook, &cub);
	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx);
	return (0);
};


