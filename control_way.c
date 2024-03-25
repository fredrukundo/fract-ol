/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:11:23 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/20 23:14:47 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_control(t_fractol *fractol)
{
	mlx_hook(fractol->win, KEYPRESS, KEYPRESSMASK, key_way, fractol);
	mlx_hook(fractol->win, BUTTONPRESS, BUTTONPRESSMASK, button_way, fractol);
	mlx_hook(fractol->win, 17, 0, ex_way, fractol);
}

int	close_window(void)
{
	write (1, "Good bye :)\n", 12);
	exit(EXIT_FAILURE);
}

int	key_way(int key, t_fractol *fractol)
{
	if (key == 53)
		close_window();
	else if (key == 124)
		fractol->shift_x += (0.2 * fractol->zoom);
	else if (key == 123)
		fractol->shift_x -= (0.2 * fractol->zoom);
	else if (key == 126)
		fractol->shift_y += (0.2 * fractol->zoom);
	else if (key == 125)
		fractol->shift_y -= (0.2 * fractol->zoom);
	else if (key == 69)
		fractol->iter += 5;
	else if (key == 78)
		fractol->iter -= 5;
	else if (key == 8)
	{
		fractol->bla_c += 100;
		fractol->wh_c += 100;
		fractol->pink_color += 100;
	}
	else
		return (0);
	fractol_building(fractol);
	return (0);
}

int	button_way(int Button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (Button == 5)
		fractol->zoom *= 1.07;
	else if (Button == 4)
		fractol->zoom *= 0.80;
	fractol_building(fractol);
	return (0);
}

int	ex_way(void)
{
	close_window();
	return (0);
}
