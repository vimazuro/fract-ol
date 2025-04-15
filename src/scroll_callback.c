/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:39 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/13 15:01:54 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	scroll_callback(double xdelta, double ydelta, void *param)
{
	t_fractal		*fractal;
	int32_t			mouse_x;
	int32_t			mouse_y;
	double			zoom_factor;
	const double	min_zoom = 10.0;

	xdelta = 0;
	fractal = (t_fractal *)param;
	mlx_get_mouse_pos(fractal->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
	{
		zoom_factor = 1.1;
		fractal->max_iterations += 20;
	}
	else if (fractal->zoom * 0.9 > min_zoom)
	{
		zoom_factor = 0.9;
		fractal->max_iterations = fmax(20, fractal->max_iterations - 20);
	}
	else
		return ;
	offset_zoom(fractal, mouse_x, mouse_y, zoom_factor);
}
