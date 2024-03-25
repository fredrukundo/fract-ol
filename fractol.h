/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:46:49 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/21 17:56:37 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# define HEIGHT 			800
# define WIDTH 				800
# define KEYPRESS 			2
# define KEYPRESSMASK		0
# define BUTTONPRESS		4
# define BUTTONPRESSMASK	0

typedef struct numcomplex
{
	double	x;
	double	y;
}			t_numcomplex;

typedef struct fractol
{
	void	*mlx;
	void	*win;
	char	*name;
	void	*img;
	char	*pixel;
	int		bpp;
	int		endian;
	int		size_line;
	int		min;
	int		max_len_of;
	int		bla_c;
	int		wh_c;
	int		pink_color;
	int		iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	souaouri_x;
	double	souaouri_y;
}			t_fractol;

t_numcomplex	power(t_numcomplex z);
t_numcomplex	sum(t_numcomplex z, t_numcomplex c);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			fractol_unit(t_fractol *fractol);
double			ft_map(double un_num, double min, double max, double max1);
void			fractol_building(t_fractol *fractol);
void			ft_control(t_fractol *fractol);
int				key_way(int keysym, t_fractol *fractol);
int				button_way(int Button, int x, int y, t_fractol *fractol);
double			julia_param(char *s);
int				ex_way(void);
size_t			ft_strlen(const char *s);

#endif