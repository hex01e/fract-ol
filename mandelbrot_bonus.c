/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:11 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/28 23:12:42 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	key_event(int code, t_mlx_data *data)
{
	if (code == 53)
		on_destroy(data);
	else if (code == 15)
	{
		data->x_ = 0;
		data->y_ = 0;
		data->zoom = 1;
		redraw(data, mandelbrot);
	}
	else
		mandelbrot_key_extra_events(code, data);
	return (1);
}

static int	mouse_event(int code, int x, int y, t_mlx_data *data)
{
	if (code == 1)
	{
		data->x = get_coord(x, WIDTH, data) + data->x_;
		data->y = get_coord(y, HEIGHT, data) + data->y_;
		redraw(data, mandelbrot);
	}
	else
		mandelbrot_mouse_extra_events(code, x, y, data);
	return (1);
}

static void	events_handler(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, on_destroy, mlx_data);
	mlx_mouse_hook(mlx_data->mlx_win, mouse_event, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, key_event, mlx_data);
}

void	mandelbrot(t_mlx_data *mlx_data)
{
	t_win_d		d;
	double		temp;
	int			iter;

	d.h = 0;
	while (d.h < HEIGHT)
	{
		d.w = 0;
		while (d.w < WIDTH)
			mandelbrot_iter_loop(&d, mlx_data);
		d.h++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img,
		0, 0);
	events_handler(mlx_data);
}
