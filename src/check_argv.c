/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:12:14 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/19 11:58:43 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	check_argv(char **argv)
{
	if ((ft_strcmp(argv[1], "Mandelbrot") != 0)
		&& (ft_strcmp(argv[1], "Julia") != 0)
		&& (ft_strcmp(argv[1], "Burning") != 0))
	{
		print_error("enter:	./fractol Mandelbrot\n\
	./fractol Julia\n	./fractol Burning\n");
	}
	else if (((ft_strcmp(argv[1], "Mandelbrot") == 0)
			|| (ft_strcmp(argv[1], "Burning") == 0)) && argv[2])
	{
		ft_printf("%s doesn't need parameters\n\
enter:	./fractol %s\n", argv[1], argv[1]);
		exit(1);
	}
	else if ((ft_strcmp(argv[1], "Julia") == 0)
		&& ((!argv[2] || !argv[3]) || argv[4]))
	{
		print_error("Julia need two digital parameters\ntry: \
	./fractol Julia -0.4 0.6\n \
	./fractol Julia 0.285 0.01\n \
	./fractol Julia -0.70176 -0.3842\n \
	./fractol Julia -0.8 0.156\n \
	./fractol Julia -0.7269 0.1889\n");
	}
	else if ((ft_strcmp(argv[1], "Julia") == 0)
		&& (ft_isfloatpoint(argv[2]) == 0 || ft_isfloatpoint(argv[3]) == 0))
		print_error("error in the parameters!\n");
}
