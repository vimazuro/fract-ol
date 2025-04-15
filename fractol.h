/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:32:04 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 12:09:54 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define WINDOW_H 1000
# define WINDOW_W 1500

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		x;
	double		y;
	int			zoom;
	int			max_iterations;
	int			color_mode;
	double		julia_a;
	double		julia_b;
	double		offset_x;
	double		offset_y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
}	t_fractal;

int		main(int argc, char **argv);
void	calculate_mandelbrot(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);
void	calculate_burning(t_fractal *fractal);
void	draw_mandelbrot(t_fractal *fractal);
void	draw_julia(t_fractal *fractal);
void	draw_burning(t_fractal *fractal);
void	scroll_callback(double xdelta, double ydelta, void *param);
void	loop_hook_m(void *param);
void	loop_hook_j(void *param);
void	loop_hook_b(void *param);
void	ft_clear_window(t_fractal *fractal);
void	offset_zoom(t_fractal *fractal, int32_t m_x, int32_t m_y,
			double zoom_f);
void	print_error(char *text);
void	check_argv(char **argv);
void	key_callback(mlx_key_data_t keydata, void *param);
void	run_mandelbrot(t_fractal *fr);
void	run_julia(t_fractal *fr);
void	run_burning(t_fractal *fr);
double	get_color(t_fractal *fractal, int iterations);

#endif
