/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:17:32 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/18 12:08:57 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	key_callback_color(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		fractal->color_mode = 1;
	else if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		fractal->color_mode = 2;
	else if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		fractal->color_mode = 3;
	else if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
		fractal->color_mode = 4;
	else if (keydata.key == MLX_KEY_5 && keydata.action == MLX_PRESS)
		fractal->color_mode = 5;
}

void	key_callback(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_1
			|| keydata.key == MLX_KEY_2 || keydata.key == MLX_KEY_3
			|| keydata.key == MLX_KEY_4 || keydata.key == MLX_KEY_5))
		key_callback_color(keydata, param);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractal->mlx);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->offset_x += 10;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->offset_x -= 10;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->offset_y += 10;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->offset_y -= 10;
}
