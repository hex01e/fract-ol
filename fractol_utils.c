/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:59:17 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/15 19:04:43 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_complex z, t_win_d d, int iter, t_mlx_data *mlx_data)
{
	int	color;
	int	px;

	px = (d.h * 4 * WIDTH)  + (d.w * 4);
	color = 0xff - iter * 1024 / ITER_MAX;
	if (z.re * z.re + z.im * z.im > 4)
	{
		mlx_data->buffer[px + 0] = color;
		mlx_data->buffer[px + 1] = color >> 8;
		mlx_data->buffer[px + 2] = color >> 16;
		mlx_data->buffer[px + 3] = color >> 24;
	}
}

void	redraw(t_mlx_data *data, void f(t_mlx_data*)){
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	f(data);
}

int	on_destroy(t_mlx_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
	return(0);
}

double	get_coord(int p, double of, t_mlx_data *data)
{
	return ((p - of / 2) * ((4.0 / data->zoom) / of));
}
