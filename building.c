/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:16:40 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/24 01:28:03 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	c_param(t_numcomplex *z, t_numcomplex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else if (!ft_strncmp(fractol->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	coloring(int x, int y, t_fractol *fractol, int color)
{
	int	offset;

	offset = (y * fractol->size_line) + (x * fractol->bpp / 8);
	*(int *)(fractol->pixel + offset) = color;
}

static void	divide_pixel(int x, int y, t_fractol *fractol)
{
	t_numcomplex	z;
	t_numcomplex	c;
	int				color;							
	int				i;

	i = 0;
	z.x = (ft_map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (ft_map(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	c_param(&z, &c, fractol);
	{
		while (i < fractol->iter)
		{
			z = sum(power(z), c);
			if ((z.x * z.x) + (z.y * z.y) > fractol->max_len_of)
			{
				color = ft_map(i, fractol->bla_c, fractol->wh_c, fractol->iter);
				coloring(x, y, fractol, color);
				return ;
			}
			++i;
		}
	}
	coloring(x, y, fractol, fractol->pink_color);
}

void	fractol_building(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			divide_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

double	ft_map(double un_num, double min, double max, double max1)
{
	return ((max - min) * (un_num - 0) / (max1 - 0) + min);
}
