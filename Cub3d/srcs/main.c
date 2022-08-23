/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 01:14:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/22 23:24:24 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


float degToRad(int a) { return a*M_PI/180.0;}

float	dist(float ax, float ay, float bx, float by, float ang)
{
	return (   sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)));	
}

int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_data *data, int beginx, int beginy, int endx, int endy)
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
		my_mlx_pixel_put(data, pixelx, pixely, 0xff0000);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return ;
}

void ft_drawwalls(t_data *data, int beginx, int beginy, int lineH)
{
	int i;

	i = 0;
	while (i < 8)				
	{
		ft_draw_line(data, beginx + i, beginy - lineH, beginx + i, beginy + lineH);
		i++;
	}
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

void	drawrays(t_data *data, int mapX, int mapY, int mapS)
{
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

	
	int r,mx,my,mp,dof; float vx,vy,rx,ry,ra,xo,yo,disV,disH,hx,hy, disT;

	//ra = data->pa;
	ra=data->pa - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	for (r = 0; r < 60; r++)
	{
		dof = 0;
		float disH;
		float aTan;
		disH = 1000000;
		hx = data->x;
		hy = data->y;
		aTan = -1/tan(ra);
		if (ra > PI){
			ry = (((int)data->y>>6)<<6) - 0.0001;
			rx = (data->y - ry) * aTan + data->x;
			yo = -64;
			xo = -yo * aTan;
			// N
		}
		if (ra < PI){
			ry = (((int)data->y>>6)<<6) + 64;
			rx = (data->y - ry) * aTan + data->x;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->x;
			ry = data->y;
			dof = 8;
			// S
		}
		while (dof < 8)
		{
			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
			if(mp > 0 && mp < mapX * mapY && map[mp]==1){hx = rx; hy = ry; disH = dist(data->x, data->y, hx, hy, ra); dof=8;}//hit
			else{ rx+=xo; ry+=yo; dof+=1;}   
		}
		// ft_draw_line(data, data->x, data->y, rx, ry);

		dof = 0;
		float nTan;
		float disV;
		disV = 1000000;
		vx = data->x;
		vy = data->y;
		nTan = -tan(ra);
		if (ra > PI2 && ra < PI3){
			rx = (((int)data->x>>6)<<6) - 0.0001;
			ry = (data->x - rx) * nTan + data->y;
			xo = -64;
			yo = -xo * nTan;
			// W
		}
		if (ra < PI2 || ra > PI3){
			rx = (((int)data->x>>6)<<6) + 64;
			ry = (data->x - rx) * nTan + data->y;
			xo = 64;
			yo = -xo * nTan;
			// E
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->x;
			ry = data->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
			if(mp > 0 && mp<mapX*mapY && map[mp]==1){vx = rx; vy = ry; disV = dist(data->x, data->y, vx, vy, ra); dof=8;}//hit
			else{ rx+=xo; ry+=yo; dof+=1;}  
		}
		if (disV > disH){rx = hx; ry = hy; disT=disH;}
		if (disV < disH){rx = vx; ry = vy; disT=disV;}
		ft_draw_line(data, data->x, data->y, rx, ry);
		//ra=data->pa - DR * 30;


		float ca = data->pa - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		disT = disT * cos(ca);
		float lineH = (mapS * 500)/disT;
		if (lineH > 500)
			lineH = 500;
		float lineO = 300 - lineH / 2;
		ft_drawwalls(data, r * 8 + 1000, lineO , lineH);








		
 		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}


// 	for (r = 0; r < 60; r++)
// 	{
//   //---Vertical---
// 	dof=0; side=0; disV=100000;
// 	float Tan=tan(degToRad(ra));
// 	if(cos(degToRad(ra))> 0.001){ rx=(((int)data->x >> 6)<<6) + 64;      ry=(data->x - rx) * Tan + data->y; xo= 64; yo =- xo * Tan;}//looking left
// 	else if(cos(degToRad(ra))<-0.001){ rx=(((int)data->x >> 6)<<6) - 0.0001; ry=(data->x - rx) * Tan + data->y; xo=-64; yo=-xo*Tan;}//looking right
// 	else { rx = data->x; ry = data->y; dof=8;}                                                  //looking up or down. no hit

// 	while(dof<8)
// 	{
// 	mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
// 	if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disV=cos(degToRad(ra))*(rx - data->x)-sin(degToRad(ra))*(ry - data->y);}//hit
// 	else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
// 	}
// 	vx=rx; vy=ry;

//   //---Horizontal---
// 	dof=0; disH=100000;
// 	Tan=1.0/Tan;
// 		if(sin(degToRad(ra))> 0.001){ ry=(((int)data->y>>6)<<6) -0.0001; rx=(data->y - ry)*Tan + data->x; yo=-64; xo=-yo*Tan;}//looking up
// 	else if(sin(degToRad(ra))<-0.001){ ry=(((int)data->y>>6)<<6)+64;      rx=(data->y-ry)*Tan+data->x; yo= 64; xo=-yo*Tan;}//looking down
// 	else{ rx=data->x; ry=data->y; dof=8;}                                                   //looking straight left or right

// 	while(dof<8)
// 	{
// 	mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;
// 	if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disH=cos(degToRad(ra))*(rx-data->x)-sin(degToRad(ra))*(ry-data->y);}//hit
// 	else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
// 	}
// 	if(disV<disH){ rx=vx; ry=vy; disH=disV;}// glColor3f(0,0.6,0);}                  //horizontal hit first

// 	ft_draw_line(data, data->x, data->y, rx, ry);
	
// //	glLineWidth(2); glBegin(GL_LINES); glVertex2i(px,py); glVertex2i(rx,ry); glEnd();//draw 2D ray
    
// 	int ca=FixAng(data->pa-ra); disH=disH*cos(degToRad(ca));                            //fix fisheye 
// 	int lineH = (mapS*320)/(disH); if(lineH>320){ lineH=320;}                     //line height and limit
// 	int lineOff = 160 - (lineH>>1);                                               //line offset

// //	glLineWidth(8);glBegin(GL_LINES);glVertex2i(r*8+530,lineOff);glVertex2i(r*8+530,lineOff+lineH);glEnd();//draw vertical wall  

// 	//ft_draw_line(data, data->x, data->y, rx, ry);

// 	ra=FixAng(ra-1);       
// 	}

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
	//my_mlx_pixel_put(data, data->x + data->pdx * 5, data->y + data->pdy * 5, 0xffff00);
	ft_draw_line(data, posx, posy, data->x + data->pdx * 5, data->y + data->pdy * 5);
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
			if (y <= posy + scale  && x <= posx + scale )
				img_color[y][x++] = 0xF3F3F2;
			else
				x++;
		}
		++y;
	}
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
	while (y < cub->mapH)
	 {
		x = 0;
		while (x < cub->mapW)
		{
			xo = x * cub->mapScale;
			yo = y * cub->mapScale;
			if(map[ y * cub->mapW + x] == 1)
			{
				ft_drawsquare(img_color, xo, yo, 64, 0x858485);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image->img, 0, 0);
}

int	render_next_frame(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlxwin);
	ft_drawmap(cub);
	ft_putplayer(cub->image, cub->image->x, cub->image->y);
	drawrays(cub->image, 8, 8, 54);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image->img, 0, 0);
	return (0);
};



int	key_hook(int keycode, t_data *data)  // direction et gauche droite
{
	if (keycode == 53)
	{
		exit (0);
	}
	if (keycode == 13)
	{
		data->x += data->pdx ;
		data->y += data->pdy ;
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
		data->x -= data->pdx ;
		data->y -= data->pdy ;
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










int main()
{
	t_cub	cub;
	t_data	img;
	t_data	img2;

	cub.mapW = 8;
	cub.mapH = 8;
	cub.mapScale = 64;
	cub.image = &img;
	img.x = 300;
	img.y = 300;
	img.pa = 0;
	img.pdx = cos(img.pa) * 5;
	img.pdy = sin(img.pa) * 5;
	cub.mlx = mlx_init();
	cub.mlxwin = mlx_new_window(cub.mlx, 1920, 1080, "Cub3D");
	img.img = mlx_new_image(cub.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
//	ft_putplayer(&img, img.x, img.y);
//	ft_drawmap(&cub);
//	mlx_put_image_to_window(cub.mlx, cub.mlxwin, img.img, 0, 0);

//	mlx_key_hook(cub.mlxwin, key_hook, &img);
	mlx_hook(cub.mlxwin, 2, 1L<<0, key_hook, &img);
	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
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

