/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:27:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/25 03:58:40 by rcuminal         ###   ########.fr       */
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
# define PI2 PI / 2
# define PI3 3 * PI / 2

# define DR 0.0174533

# define N	'N'
# define S	'S'
# define E	'E'
# define O	'O'

typedef struct s_pos
{
	
	float		x;		// pose
	float		y;
	float		pdx;	// Delta x et y deplacement
	float		pdy;	
	float		pa;		//player angle

}					t_pos;


typedef struct s_raycasting
{
	char		dir;
	float		disV;
	float		disH;
	float		disT;

	float		lineH;
	float		lineO;
	

	float		aTan;
	float		nTan;

	float		ra;
	float		rayX;
	float		rayY;
	float		vertx;
	float		verty;
	float		horix;
	float		horiy;
	float		xo;
	float		yo;
	float		ca;

}					t_raycasting;


typedef struct s_image
{
	
	void	*img;
	char	*addr;
	u_int32_t	**arr;
	
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
}					t_image;


typedef struct cub
{
	void	*mlx;
	void	*mlxwin;

	int		map[64];

	int		mapW;
	int		mapH;
	int		mapScale;
	int		xo;
	int		yo;



	t_raycasting	data;
	t_pos			pos;
	t_image		image[3];
}					t_cub;




#endif