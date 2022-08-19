/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:27:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/19 04:57:44 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libmlx/mlx.h"
# include "../tracker/include/tracker.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>


# define PI 3.1415926535

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float		x;
	float		y;
	float		pdx;
	float		pdy;
	float		pa;
	int		move;
}					t_data;

typedef struct cub
{
	void	*mlx;
	void	*mlxwin;
	// int		**pars;
	// int		**color;
	// int		x;
	// int		y;
	// int		fd;
	// t_pos	pos;
	// t_var	var;
	t_data	*image;
}					t_cub;




#endif