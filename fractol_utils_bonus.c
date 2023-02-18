/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:23:34 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/18 22:44:20 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw(t_complex z, t_win_d d, int iter, t_mlx_data *data)
{
	int r;
	int	g;
	int	b;
	double	i;

	i = (double) iter / ITER_MAX ;
	r = 8.5 * (1 - i) * i * i * i * 255;
	g = 14.4 * (1 - i) * (1 - i) * i * i * 255 ;
	b = 8.5  * (1 - i) * (1 - i) * (1 - i) * i * 255;
	data->buffer[d.h * data->line_bytes / 4 + d.w] = r << 16 | g << 8 | b;
}

void	redraw(t_mlx_data *data, void fractol(t_mlx_data*)){
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	fractol(data);
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
