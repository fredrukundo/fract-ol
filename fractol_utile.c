/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:59:59 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/25 17:03:16 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_numcomplex	sum(t_numcomplex z, t_numcomplex c)
{
	t_numcomplex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_numcomplex	power(t_numcomplex z)
{
	t_numcomplex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

static void	ft_error3(void)
{
	write (2, "incorrect parameter\n", 21);
	exit(EXIT_FAILURE);
}

double	julia_param(char *s)
{
	double	nb_float;
	double	pow;
	int		sign;

	nb_float = 0;
	pow = 1;
	sign = 1;
	if (*s == '\0')
		ft_error3();
	if (*s == 43 || *s == 45)
		if (*s++ == 45)
			sign = -1;
	while (*s != '.' && *s && *s >= '0' && *s <= '9')
		nb_float = (nb_float * 10) + (*s++ - 48);
	s += (*s == '.') * 1;
	while (*s && *s >= '0' && *s <= '9')
	{
		pow /= 10;
		nb_float = nb_float + ((*s++ - 48) * pow);
	}
	if (*s != '\0')
		ft_error3();
	return (nb_float * sign);
}
