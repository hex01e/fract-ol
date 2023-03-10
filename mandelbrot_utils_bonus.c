/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:20:35 by houmanso          #+#    #+#             */
/*   Updated: 2023/03/01 18:04:57 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandelbrot_iter_loop(t_win_d *d, t_mlx_data *mlx_data)
{
	t_complex	c;
	t_complex	z;
	double		temp;
	int			iter;

	iter = 0;
	z.re = 0;
	z.im = 0;
	c.re = get_coord(d->w, WIDTH, mlx_data) + mlx_data->x_;
	c.im = get_coord(d->h, HEIGHT, mlx_data) + mlx_data->y_;
	while (z.re * z.re + z.im * z.im <= 4 && iter <= mlx_data->max)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	draw(*d, iter, mlx_data);
	d->w++;
}

void	mandelbrot_key_extra_events(int code, t_mlx_data *data)
{
	if (code == 123)
	{
		data->x_ -= 0.2 / data->zoom ;
		redraw(data, mandelbrot);
	}
	else if (code == 124)
	{
		data->x_ += 0.2 / data->zoom;
		redraw(data, mandelbrot);
	}
	else if (code == 125)
	{
		data->y_ += 0.2 / data->zoom;
		redraw(data, mandelbrot);
	}
	else if (code == 126)
	{
		data->y_ -= 0.2 / data->zoom;
		redraw(data, mandelbrot);
	}
	else
	{
		data->color = code;
		redraw(data, mandelbrot);
	}
}

void	mandelbrot_mouse_extra_events(int code, int x, int y, t_mlx_data *data)
{
	double	temp_x;
	double	temp_y;

	if (code == 4)
	{
		temp_x = get_coord(x, WIDTH, data);
		temp_y = get_coord(y, WIDTH, data);
		data->zoom *= 1.2;
		data->x_ += (temp_x - get_coord(x, WIDTH, data));
		data->y_ += (temp_y - get_coord(y, WIDTH, data));
		redraw(data, mandelbrot);
	}
	else if (code == 5)
	{
		data->max += 5;
		temp_x = get_coord(x, WIDTH, data);
		temp_y = get_coord(y, WIDTH, data);
		data->zoom /= 1.2;
		data->x_ += (temp_x - get_coord(x, WIDTH, data));
		data->y_ += (temp_y - get_coord(y, WIDTH, data));
		redraw(data, mandelbrot);
	}
}
