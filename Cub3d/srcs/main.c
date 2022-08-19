/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:14:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/19 05:05:18 by Romain           ###   ########.fr       */
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

void ft_putplayer(t_data *data, int posx, int posy)
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


int	render_next_frame(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image->img);
	cub->image->img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->image->addr = mlx_get_data_addr(cub->image->img, &cub->image->bits_per_pixel, &cub->image->line_length,
								&cub->image->endian);
	mlx_clear_window(cub->mlx, cub->mlxwin);
	ft_putplayer(cub->image, cub->image->x, cub->image->y);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image->img, 0, 0);
	return (0);
};



int	key_hook(int keycode, t_data *data)
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
	// if (data->x > 1920)
	// 	data->x = 0;
	// if (data->x < 1920)
	// 	data->x = 1920;
	// if (data->y > 1080)
	// 	data->y = 0;
	// if (data->y < 1080)
	// 	data->y = 1080;
	return (0);
}



int main()
{
	t_cub	cub;
	t_data	img;
	t_data	img2;

	img.move = 1;

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

	int save = 0;
	
		save = img.move;
		ft_putplayer(&img, img.x, img.y);
		mlx_put_image_to_window(cub.mlx, cub.mlxwin, img.img, 0, 0);
	//	mlx_destroy_image(cub.mlx, img.img);
		//mlx_clear_window(cub.mlx, cub.mlxwin);
	//	dprintf(2, "-->%d\n", img.move);
	
	mlx_key_hook(cub.mlxwin, key_hook, &img);
		
	
	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx);
	
	

	


	//mlx_destroy_window(cub.mlx, cub.mlxwin);




	
	//mlx_put_image_to_window(cub.mlx, cub.mlxwin, img2.img, 0, 0);
	return (0);
};


	//cub.mlx = mlx_init();
	//cub.mlxwin = mlx_new_window(cub.mlx, 1920, 1080, "Cub3D");


	//img.img = mlx_new_image(cub.mlx, 1920, 1080);
	// img2.img = mlx_new_image(cub.mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	//							&img.endian);
	// img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
	// 							&img2.endian);
	// uint32_t**	img_color = ft_mem2array((uint32_t*) img.addr, 1920, 1080);
	// uint32_t**	img2_color = ft_mem2array((uint32_t*) img2.addr, 1920, 1080);
	// int i = 0;
	// // while (i < 1080)
	// // {
	// // 	img_color[i][500] = 0xff0000;
	// // 	++i;
	// // }

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

	// image player on the map
	
	
	// int i = 0;
	// i = 0;
	// while (i < 1080)
	// {
	// 	int j = 0;
	// 	while (j < 1920)
	// 	{
	// 		if (i >= 540 && i <= 550 && j >= 450 && j <= 460)
	// 			img_color[i][j++] = 0xffff00;
	// 		j++;
	// 	}
	// 	++i;
	// }
