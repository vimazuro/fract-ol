/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:56:42 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:20 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_clear_window(t_fractal *fractal)
{
	int	i;
	int	total_pixels;

	i = 0;
	total_pixels = fractal->img->width * fractal->img->height;
	while (i < total_pixels)
	{
		fractal->img->pixels[i] = 0x00000000;
		i++;
	}
}
