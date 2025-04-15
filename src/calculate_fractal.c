/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:51:18 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 11:56:14 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	color;
	double	x_temp;
	double	scale;

	scale = 1.0 / fractal->zoom;
	fractal->cx = (fractal->x - (fractal->mlx->width / 2)
			+ fractal->offset_x) * scale;
	fractal->cy = (fractal->y - (fractal->mlx->height / 2)
			+ fractal->offset_y) * scale;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	i = 0;
	while (i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
		i++;
	}
	color = get_color(fractal, i);
	mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
}

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	color;
	double	x_temp;
	double	scale;

	scale = 1.0 / fractal->zoom;
	fractal->zx = (fractal->x - (fractal->mlx->width / 2)
			+ fractal->offset_x) * scale;
	fractal->zy = (fractal->y - (fractal->mlx->height / 2)
			+ fractal->offset_y) * scale;
	i = 0;
	while (i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->julia_a;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->julia_b;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
		i++;
	}
	color = get_color(fractal, i);
	mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
}

void	calculate_burning(t_fractal *fractal)
{
	int		i;
	double	color;
	double	x_temp;
	double	scale;

	scale = 1.0 / fractal->zoom;
	fractal->cx = (fractal->x - (fractal->mlx->width / 2)
			+ fractal->offset_x) * scale;
	fractal->cy = (fractal->y - (fractal->mlx->height / 2)
			+ fractal->offset_y) * scale;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	i = 0;
	while (i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2.0 * fabs(fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy > 4.0)
			break ;
		i++;
	}
	color = get_color(fractal, i);
	mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
}
