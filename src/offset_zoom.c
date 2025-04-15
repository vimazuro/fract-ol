/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:27:38 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:35 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	offset_zoom(t_fractal *fractal, int32_t m_x, int32_t m_y, double zoom_f)
{
	double	scale;
	double	old_cx;
	double	old_cy;
	double	dx;
	double	dy;

	scale = 1.0 / fractal->zoom;
	old_cx = (m_x - fractal->mlx->width / 2 + fractal->offset_x) * scale;
	old_cy = (m_y - fractal->mlx->height / 2 + fractal->offset_y) * scale;
	fractal->zoom *= zoom_f;
	scale = 1.0 / fractal->zoom;
	dx = old_cx - (m_x - fractal->mlx->width / 2 + fractal->offset_x) * scale;
	dy = old_cy - (m_y - fractal->mlx->height / 2 + fractal->offset_y) * scale;
	fractal->offset_x += dx * fractal->zoom;
	fractal->offset_y += dy * fractal->zoom;
}
