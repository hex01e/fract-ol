/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:45:47 by houmanso          #+#    #+#             */
/*   Updated: 2023/03/01 18:05:48 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_iter_loop(t_mlx_data *mlx_data, t_win_d *d, t_complex *c)
{
	int			iter;
	double		temp;
	t_complex	z;

	z.re = get_coord(d->w, WIDTH, mlx_data) + mlx_data->x_;
	z.im = get_coord(d->h, HEIGHT, mlx_data) + mlx_data->y_;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter <= mlx_data->max)
	{
		temp = z.re * z.re - z.im * z.im + c->re;
		z.im = 2 * z.re * z.im + c->im;
		z.re = temp;
		iter++;
	}
	draw(*d, iter, mlx_data);
	d->w++;
}

void	julia_key_extra_events(int code, t_mlx_data *data)
{
	if (code == 123)
	{
		data->x_ -= 0.2 / data->zoom ;
		redraw(data, julia);
	}
	else if (code == 124)
	{
		data->x_ += 0.2 / data->zoom;
		redraw(data, julia);
	}
	else if (code == 125)
	{
		data->y_ += 0.2 / data->zoom;
		redraw(data, julia);
	}
	else if (code == 126)
	{
		data->y_ -= 0.2 / data->zoom;
		redraw(data, julia);
	}
	else
	{
		data->color = code;
		redraw(data, julia);
	}
}

void	julia_mouse_extra_events(int code, int x, int y, t_mlx_data *data)
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
		redraw(data, julia);
	}
	else if (code == 5)
	{
		temp_x = get_coord(x, WIDTH, data);
		temp_y = get_coord(y, WIDTH, data);
		data->zoom /= 1.2;
		data->x_ += (temp_x - get_coord(x, WIDTH, data));
		data->y_ += (temp_y - get_coord(y, WIDTH, data));
		redraw(data, julia);
	}
}
