/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:25:04 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 11:56:08 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	run_mandelbrot(t_fractal *fr)
{
	draw_mandelbrot(fr);
	mlx_key_hook(fr->mlx, key_callback, fr);
	mlx_scroll_hook(fr->mlx, scroll_callback, fr);
	mlx_loop_hook(fr->mlx, loop_hook_m, fr);
	mlx_loop(fr->mlx);
	mlx_terminate(fr->mlx);
}

void	run_julia(t_fractal *fr)
{
	draw_julia(fr);
	mlx_key_hook(fr->mlx, key_callback, fr);
	mlx_scroll_hook(fr->mlx, scroll_callback, fr);
	mlx_loop_hook(fr->mlx, loop_hook_j, fr);
	mlx_loop(fr->mlx);
	mlx_terminate(fr->mlx);
}

void	run_burning(t_fractal *fr)
{
	draw_burning(fr);
	mlx_key_hook(fr->mlx, key_callback, fr);
	mlx_scroll_hook(fr->mlx, scroll_callback, fr);
	mlx_loop_hook(fr->mlx, loop_hook_b, fr);
	mlx_loop(fr->mlx);
	mlx_terminate(fr->mlx);
}
