/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:53 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:16 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	int32_t	x;
	int32_t	y;

	x = 0.0;
	while (x < fractal->mlx->width)
	{
		y = 0.0;
		while (y < fractal->mlx->height)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_mandelbrot(fractal);
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

void	draw_julia(t_fractal *fractal)
{
	int32_t	x;
	int32_t	y;

	x = 0.0;
	while (x < fractal->mlx->width)
	{
		y = 0.0;
		while (y < fractal->mlx->height)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_julia(fractal);
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

void	draw_burning(t_fractal *fractal)
{
	int32_t	x;
	int32_t	y;

	x = 0.0;
	while (x < fractal->mlx->width)
	{
		y = 0.0;
		while (y < fractal->mlx->height)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_burning(fractal);
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
