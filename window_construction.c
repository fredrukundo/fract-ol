/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_construction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:20:13 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/24 00:46:54 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_param(t_fractol *fractol)
{
	fractol->max_len_of = 8;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->iter = 127;
	fractol->zoom = 1.0;
	fractol->bla_c = 0x000000;
	fractol->wh_c = 0xFFFFFF;
	fractol->pink_color = 0xff0bac;
}

static void	error(t_fractol *fractol)
{
	perror ("error : window can't open");
	free (fractol->mlx);
	exit (EXIT_FAILURE);
}

void	fractol_unit(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		error (fractol);
	fractol->win = mlx_new_window(fractol->mlx, HEIGHT, WIDTH, fractol->name);
	if (fractol->win == NULL)
		error (fractol);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (fractol->img == NULL)
	{
		mlx_destroy_image(fractol->mlx, fractol->win);
		error (fractol);
	}
	fractol->pixel = mlx_get_data_addr(fractol->img, &fractol->bpp,
			&fractol->size_line, &fractol->endian);
	if (fractol->pixel == NULL)
		error(fractol);
	ft_control(fractol);
	fractol_param(fractol);
}
