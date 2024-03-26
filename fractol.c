/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:52:03 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 19:52:04 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	if (ft_strlen(s1) - ft_strlen(s2) != 0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]) && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	ft_error1(void)
{
	char		*m_err;

	m_err = "please chose mandelbrot or \"julia p_r p_i\"\n";
	write (2, m_err, 44);
	exit (EXIT_FAILURE);
}

static void	ft_error(void)
{
	write (2, "this display cannot support these dimensions\n", 46);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (HEIGHT < 0 || HEIGHT > 2880)
		ft_error();
	if (WIDTH < 0 || WIDTH > 5120)
		ft_error();
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractol.julia_x = julia_param(argv[2]);
			fractol.julia_y = julia_param(argv[3]);
		}
		fractol_unit(&fractol);
		fractol_building(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		ft_error1();
}
