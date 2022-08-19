/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:14:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/19 17:57:03 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

u_int32_t**	ft_mem2array(uint32_t *mem, size_t len_x, size_t len_y)
{
	u_int32_t**	arr;
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

void ft_putplayer(t_data *data, int posx, int posy) // petit carre avec direction grace a un point
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	uint32_t**	img_color = ft_mem2array((uint32_t*) data->addr, 1920, 1080);
	while (y < 1080)
	{
		int x = 0;
		while (x < 1920)
		{
			if (y >= posy - 5 && y <= posy + 5 && x >= posx -5 && x <= posx + 5)
				img_color[y][x++] = 0xffff00;
			else
				img_color[y][x++] = 0xff000000;
		}
		++y;
	}
	//img_color[data->y + data->pdy * 5][data->x + data->pdx * 5] = 0xffff00;
	my_mlx_pixel_put(data, data->x + data->pdx * 5, data->y + data->pdy * 5, 0xffff00);
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
			if (y <= posy + scale && x <= posx + scale)
				img_color[y][x++] = 0xF3F3F2;
			else
				x++;
		}
		++y;
	}
}




int	render_next_frame(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image->img);
	cub->image->img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->image->addr = mlx_get_data_addr(cub->image->img, &cub->image->bits_per_pixel, &cub->image->line_length,
								&cub->image->endian);
	mlx_clear_window(cub->mlx, cub->mlxwin);
	mlx_do_key_autorepeaton(cub->mlx);
	ft_putplayer(cub->image, cub->image->x, cub->image->y);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image->img, 0, 0);
	return (0);
};



int	key_hook(int keycode, t_data *data)  // direction et gauche droite
{
	if (keycode == 13)
	{
		data->x += data->pdx;
		data->y += data->pdy;
	}
	if (keycode == 2)
	{
		data->pa += 0.1;
		if(data->pa > 2 * PI)
			data->pa -= 2 * PI;
		data->pdx = cos(data->pa) * 5;
		data->pdy = sin(data->pa) * 5;
	}
	if (keycode == 1)
	{
		data->x -= data->pdx;
		data->y -= data->pdy;
	}
	if (keycode == 0)
	{
		data->pa -= 0.1;
		if(data->pa < 0)
			data->pa += 2 * PI;
		data->pdx = cos(data->pa) * 5;
		data->pdy = sin(data->pa) * 5;
	}
	if (data->x > 1920)
		data->x = 0;
	if (data->x < 0)
		data->x = 1920;
	if (data->y > 1080)
		data->y = 0;
	if (data->y < 0)
		data->y = 1080;
	return (0);
}

void ft_drawmap(t_cub *cub)
{
	int map[]=           //the map array. Edit to change level but keep the outer walls
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
	uint32_t**	img_color = ft_mem2array((uint32_t*) cub->image->addr, 1920, 1080);
	int x,y,xo,yo;
	x = 0;
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
			img_color[y][x++] = 0x000000;
		++y;
	}
	y = 0;
	while(y < cub->mapH)
 	{
		x = 0;
		while(x < cub->mapW)
  		{
			xo = x * cub->mapScale;
			yo = y * cub->mapScale;
			if(map[ y * cub->mapW + x] == 1)
			{ 
				ft_drawsquare(img_color, xo + 10, yo + 10 , 128, 0x858485);
			}
			// else
			// {
			// 	ft_drawsquare(img_color, xo, yo, 128, 0xf3f3f2);
			// }
			// xo = x * cub->mapScale;
			// yo = y * cub->mapScale;
			// glBegin(GL_QUADS); 
			// glVertex2i( 0   +xo+1, 0   +yo+1); 
			// glVertex2i( 0   +xo+1, mapS+yo-1); 
			// glVertex2i( mapS+xo-1, mapS+yo-1);  
			// glVertex2i( mapS+xo-1, 0   +yo+1); 
			// glEnd();
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image->img, 0, 0);
}








int main()
{
	t_cub	cub;
	t_data	img;
	t_data	img2;

	cub.mapW = 8;
	cub.mapH = 8;
	cub.mapScale = 128;

	cub.image = &img;
	img.x = 250;
	img.y = 250;
	img.pa = 15;
	img.pdx = cos(img.pa) * 5;
	img.pdy = sin(img.pa) * 5;
	cub.mlx = mlx_init();
	cub.mlxwin = mlx_new_window(cub.mlx, 1920, 1080, "Cub3D");

	img.img = mlx_new_image(cub.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

//	ft_putplayer(&img, img.x, img.y);
	ft_drawmap(&cub);
	mlx_put_image_to_window(cub.mlx, cub.mlxwin, img.img, 0, 0);


	//mlx_key_hook(cub.mlxwin, key_hook, &img);
//	mlx_hook(cub.mlxwin, 2, 1L<<0, key_hook, &img);
		
	
//	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx);
	return (0);
};



	// // image 1 font
	// i = 0;
	// while (i < 1080)
	// {
	// 	int j = 0;
	// 	while (j < 1920)
	// 	{
	// 		if (i >= 540)
	// 			img_color[i][j++] = 0x003300;
	// 		else
	// 			img_color[i][j++] = 0x000033;
	// 	}
	// 	++i;
	// }

	// // image 2 wall
	// i = 0;
	// while (i < 1080)
	// {
	// 	int j = 0;
	// 	while (j < 1920)
	// 	{
	// 		if (i >= 160 && i <= 920 && j >= 400 && j <= 1520)
	// 			img2_color[i][j++] = 0xff9933;
	// 		else
	// 			img2_color[i][j++] = 0xff000000;
				
	// 	}
	// 	++i;
	// }

