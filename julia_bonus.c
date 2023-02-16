/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:29 by houmanso          #+#    #+#             */
/*   Updated: 2023/02/13 16:04:08 by houmanso         ###   ########.fr       */
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
		redraw(data, julia);
	}
	else if (code == 123)
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
	return (1);
}

static int	mouse_event(int code, int x, int y, t_mlx_data *data)
{
	double	temp_x;
	double	temp_y;
	if (code == 1)
	{
		data->x = get_coord(x, WIDTH, data) + data->x_;
		data->y = get_coord(y, HEIGHT, data) + data->y_;
		redraw(data, julia);
	}
	else if (code == 4)
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
	 return (1);
}

static void	events_handler(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, on_destroy,mlx_data);
	mlx_mouse_hook(mlx_data->mlx_win, mouse_event, mlx_data);
	mlx_key_hook(mlx_data->mlx_win, key_event, mlx_data);
}

void	julia(t_mlx_data *mlx_data)
{
	t_win_d		d;
	t_complex	c;

	d.h = 0;
	c.im = mlx_data->y;
	c.re = mlx_data->x;
	while (d.h < HEIGHT)
	{
		d.w= 0;
		while (d.w < WIDTH)
			julia_iter_loop(mlx_data, &d, &c);
		d.h++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img, 0, 0);
	events_handler(mlx_data);
}