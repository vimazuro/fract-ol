/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:48:42 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:29 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	loop_hook_m(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	ft_clear_window(fractal);
	draw_mandelbrot(fractal);
}

void	loop_hook_j(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	ft_clear_window(fractal);
	draw_julia(fractal);
}

void	loop_hook_b(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	ft_clear_window(fractal);
	draw_burning(fractal);
}
