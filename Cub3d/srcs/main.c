/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:14:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/13 04:26:12 by rcuminal         ###   ########.fr       */
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

int	render_next_frame(t_data *data)
{
	return (0);
};

int main()
{
	t_cub	cub;
	t_data	img;
	t_data	img2;

	cub.mlx = mlx_init();
	cub.mlxwin = mlx_new_window(cub.mlx, 1920, 1080, "Cub3D");


	img.img = mlx_new_image(cub.mlx, 1920, 1080);
	img2.img = mlx_new_image(cub.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
								&img2.endian);
	uint32_t**	img_color = ft_mem2array((uint32_t*) img.addr, 1920, 1080);
	uint32_t**	img2_color = ft_mem2array((uint32_t*) img2.addr, 1920, 1080);
	int i = 0;
	while (i < 1080)
	{
		img_color[i][500] = 0xff0000;
		++i;
	}
	i = 0;
	while (i < 1080)
	{
		int j = 0;
		while (j < 1920)
		{
			if (j == i)
				img2_color[i][j++] = 0x00ff00;
			else if (j < i)
				img2_color[i][j++] = 0xff00ff;
			else
				img2_color[i][j++] = 0xff000000;
		}
		++i;
	}
	i = 0;
	while (i < 1920)
	{
		img2_color[500][i] = 0x0000ff;
		++i;
	}
	
	mlx_put_image_to_window(cub.mlx, cub.mlxwin, img.img, 0, 0);
	mlx_put_image_to_window(cub.mlx, cub.mlxwin, img2.img, 0, 0);

	//mlx_loop_hook();
	mlx_loop(cub.mlx);
	return (0);
};
