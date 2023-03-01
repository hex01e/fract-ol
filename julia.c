/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:41:14 by houmanso          #+#    #+#             */
/*   Updated: 2023/03/01 23:22:16 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_event(int code, t_mlx_data *data)
{
	if (code == 1)
	{
		data->zoom = 1;
		redraw(data, julia);
	}
	else if (code == 53)
		on_destroy(data);
	else if (code == 15)
	{
		data->zoom = 1;
		redraw(data, julia);
	}
	return (1);
}

static int	mouse_event(int code, int x, int y, t_mlx_data *data)
{
	if (code == 1)
	{
		data->x = get_coord(x, WIDTH, data);
		data->y = get_coord(y, HEIGHT, data);
		redraw(data, julia);
	}
	else if (code == 4)
	{
		data->zoom *= 1.2;
		redraw(data, julia);
	}
	else if (code == 5)
	{
		data->zoom /= 1.2;
		redraw(data, julia);
	}
	return (1);
}

static void	catch_events(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, on_destroy, mlx_data);
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
		d.w = 0;
		while (d.w < WIDTH)
			julia_iter_loop(&d, c, mlx_data);
		d.h++;
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->img,
		0, 0);
	catch_events(mlx_data);
}
