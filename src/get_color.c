/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:03:16 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 10:41:23 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	get_color(t_fractal *fractal, int iterations)
{
	if (iterations == fractal->max_iterations)
		return (0x000000FF);
	else if (fractal->color_mode == 1)
		return (iterations * 0x11B8FCFF);
	else if (fractal->color_mode == 2)
		return (iterations * 0x11F088FF);
	else if (fractal->color_mode == 3)
		return (iterations * 0xFFB811FF);
	else if (fractal->color_mode == 4)
		return (iterations * 0xD5020FFF);
	else if (fractal->color_mode == 5)
		return (iterations * 0xC500EAFF);
	else
		return (iterations * 0x11B8FCFF);
}
