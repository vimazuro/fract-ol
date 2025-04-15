/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:58:58 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/19 11:38:36 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fr;

	if (argc < 2)
		print_error("enter the fractal name (Mandelbrot, Julia, Burning)\n");
	check_argv(argv);
	fr.mlx = mlx_init(WINDOW_W, WINDOW_H, argv[1], false);
	if (!fr.mlx)
		print_error("error: mlx_init\n");
	fr.img = mlx_new_image(fr.mlx, fr.mlx->width, fr.mlx->height);
	if (!fr.img)
		print_error("error: mlx_new_image\n");
	fr.zoom = 300.0;
	fr.max_iterations = 50;
	fr.color_mode = 1;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		run_mandelbrot(&fr);
	else if (ft_strcmp(argv[1], "Burning") == 0)
		run_burning(&fr);
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		fr.julia_a = ft_atof(argv[2]);
		fr.julia_b = ft_atof(argv[3]);
		run_julia(&fr);
	}
	return (0);
}
